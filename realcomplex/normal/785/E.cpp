#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)2e5 + 9;
const int K = 600;
vector<pii> Qr[K];

int p[N];

int n;
bool chn[N];

int tree[N * 2];
int m;

void add(int id){   
    id += m;
    while(id > 0){
        tree[id] ++ ;
        id >>=1;
    }
}

int res;

int query(int l, int r){
    l += m;
    r += m;
    res = 0;
    while(l <= r){
        if(l % 2 == 1) res += tree[l ++ ];
        if(r % 2 == 0) res += tree[r -- ];
        l>>=1;
        r>>=1;
    }
    return res;
}

vector<int> tpos;

struct Q{
    int pos;
    int val;
    int sign;
};

vector<Q> qri[N];

int pos[N];

void answer(int id){
    if(Qr[id].empty())
        return;
    for(int i = 1; i <= 2*m; i ++ )
        tree[i] = 0;
    for(int i = 1; i <= n; i ++ ){
        chn[i] = false;
    }
    for(auto z : Qr[id]){
        chn[z.fi] = true; 
        chn[z.se] = true;
    }
    for(int i = 1; i <= n; i ++ )
        qri[i].clear();
    for(int i = 1; i <= n; i ++ ){
        pos[p[i]] = i;
        if(chn[i])
            pos[p[i]] = -1;
    }
    ll inv1 = 0;
    tpos.clear();
    ll pref = 0;
    for(int i = 1; i <= n; i ++ ){
        if(chn[i]){
            pref += query(p[i]+1,n);
            tpos.push_back(i);
        }
        else{
            inv1 += query(p[i]+1, n);
            add(p[i]);
        }
    }
    for(int i = 1; i <= 2 * m ; i ++ )
        tree[i] = 0;
    for(int i = n; i >= 1; i -- ){
        if(chn[i]){
            pref += query(1,p[i]-1);
        }
        else{
            add(p[i]);
        }
    }
    ll inv2 = 0;
    for(int i = 0 ; i < tpos.size(); i ++ ){
        for(int j = i + 1 ; j < tpos.size(); j ++ ){
            inv2 += (p[tpos[j]] < p[tpos[i]]);
        }
    }
    vector<ll> answ;
    int b1, b2;
    int n1, n2;
    vector<ll> qir;
    for(auto &sw : Qr[id]){
        if(sw.fi > sw.se)
            swap(sw.fi, sw.se);
        qri[p[sw.fi]].push_back({sw.fi, (int)answ.size(), -1});
        qri[p[sw.se]].push_back({sw.se, (int)answ.size(), -1});
        if(sw.fi != sw.se){
            for(auto x : tpos){
                if(x > sw.fi && x < sw.se){
                    if(p[x] < p[sw.fi])
                        inv2 --;
                    if(p[x] > p[sw.se])
                        inv2 -- ;
                }
            }
        }
        
        swap(p[sw.fi], p[sw.se]);
        
        qri[p[sw.fi]].push_back({sw.fi, (int)answ.size(), +1});
        qri[p[sw.se]].push_back({sw.se, (int)answ.size(), +1});
        
        if(sw.fi != sw.se){
            for(auto x : tpos){
                if(x > sw.fi && x < sw.se){
                    if(p[x] < p[sw.fi])
                        inv2 ++;
                    if(p[x] > p[sw.se])
                        inv2 ++ ;
                }
            }
        }
        
        if(p[sw.fi] < p[sw.se]){
            inv2 -- ;
        }
        else if(p[sw.fi] > p[sw.se]){
            inv2 ++ ;
        }
        
        answ.push_back(inv1 + inv2);
        qir.push_back(0);
    }
    for(int i = 1; i <= 2*m; i ++ )
        tree[i] = 0;
    for(int i = 1; i <= n; i ++ ){
        if(pos[i] != -1){
            add(pos[i]);
        }
        for(auto qq : qri[i]){
            qir[qq.val] += query(qq.pos+1, n) * qq.sign;
        }
    }
    for(int i = 1; i <= 2 * m ; i ++ )
        tree[i] = 0;
    for(int i = n; i >= 1; i -- ){
        if(pos[i] != -1){
            add(pos[i]);
        }
        for(auto qq : qri[i]){
            qir[qq.val] += query(1, qq.pos-1) * qq.sign;
        }
    }
   
    for(int i = 0 ; i < qir.size(); i ++ ){
        pref += qir[i];
        answ[i] += pref;
    }
    for(auto rs : answ)
        cout << rs << "\n";
}

int main(){
    fastIO;
    int q;
    cin >> n >> q;
    m = n + 1;
    for(int i = 1; i <= n; i ++ )
        p[i] = i;
    int a, b;
    for(int i = 0 ; i < q; i ++ ){
        cin >> a >> b;
        Qr[i/K].push_back(mp(a, b));
    }
    for(int i = 0 ; i < K ; i ++ ){
        answer(i);
    }
    return 0;
}