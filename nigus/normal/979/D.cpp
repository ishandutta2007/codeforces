#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;

ll tot = 0;

struct trie{
    ll level = 0;
    bool b0 = 0;
    bool b1 = 0;
    ll id = 0;
    trie *t0;
    trie *t1;
};

ll tlog = 17;

ll n,m,q;
ll T;

trie mt(int l){
    trie res;
    res.level = l;
    res.id = tot;
    tot++;
    return res;
}

void insert_trie(int i, trie *tr){
   // cout <<"i: " <<  i << "  lvl" << tr->level << "   id: " << tr->id << "\n";
    ll lvl = tr->level;
    if(lvl == -1)return;
    ll bit = ((1 << lvl)&i);
    if(bit == 0){
        if(tr->b0 == 0){
            tr->b0 = 1;
            trie *nt = new trie;
            nt->level = lvl-1;
            nt->id = tr->id;
            tot++;
            tr->t0 = nt;
        }
        insert_trie(i^bit,tr->t0);
    }
    else{
        if(tr->b1 == 0){
            tr->b1 = 1;
            trie *nt = new trie;
            nt->level = lvl-1;
            nt->id = tr->id;
            tot++;
            tr->t1 = nt;
        }
        insert_trie(i^bit,tr->t1);
    }
}

ll maximize(int i, trie *tr, int ma, int curr){

    //cout << "i: " << i << " ma: " << ma << "  curr: " << curr << "   id: " << tr->id << "\n";

    ll lvl = tr->level;
    if(lvl == -1)return 0;
    ll bit = ((1 << lvl)&i);
    bool b = !(bit!=0);

    ll ny = curr + (1 << lvl);
    ll extra = 0;

    if((b == 1 && ny <= ma && tr->b1 == 1) || (b == 0 && ny <= ma && tr->b0 == 0 && tr->b1 == 1)){
        extra = (1 << lvl) * b;
       // if(lvl < 3)cout << " 1 i: " << i << "   lvl: " << lvl << "  ny: " << ny << "\n";
       ll ans2 = extra+maximize(i,tr->t1,ma,ny);
        if(ans2 >= 0)return extra+maximize(i,tr->t1,ma,ny);
    }
    if(tr->b0 == 1){
        extra = (1 << lvl) * (!b);
       // if(lvl < 3)cout << " 2 i: " << i << "   lvl: " << lvl<< "  ny: " << ny  << "\n";
        return extra+maximize(i,tr->t0,ma,curr);
    }
    return -big;
}

bool B[300001] = {0};
set<ll> S;

ll lim = 200;

vector<trie> VT;

int main() {

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,e;

    for(int c1 = 0; c1 < lim+1; c1++){
        trie nt = trie();
        nt.level = 17;
        nt.id = c1;
        tot++;
        VT.push_back(nt);
    }

    cin >> q;
    for(int c1 = 0; c1 < q; c1++){
        cin >> a;
        if(a == 1){
            cin >> b;
            if(S.find(b) == S.end()){
                B[b] = 1;
                S.insert(b);

                for(int c1 = 1; c1 < lim; c1++){
                    if(b%c1 == 0)insert_trie(b,&VT[c1]);
                }

            }
        }
        else{
            ll x,k,s;
            cin >> x >> k >> s;
            s -= x;
            if(x%k != 0){
                cout << "-1\n";
                continue;
            }
            if(k >= lim){
                ll ans = -1;
                for(int c2 = k; c2 <= min(100000ll,s); c2 += k){
                    if(B[c2])ans = max(ans,x^c2);
                }
                if(ans == -1){
                    cout << ans << "\n";
                }
                else{
                    cout << (ans^x) << "\n";
                }
            }
            else{
                ll ans = maximize(x,&VT[k],s,0);
                if(ans < 0){
                    cout << -1 << "\n";
                }
                else{
                    cout << (ans^x) << "\n";
                }
            }
        }
    }


    return 0;
}