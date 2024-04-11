#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 100;
const ll INF = (ll)1e18;

int ban;

struct myset{
    set<pii> val; // id -> v
    multiset<ll> vv; // just values
    ll sum;
    void delet(pii x){
        val.erase(x);
        vv.erase(vv.find(x.se));
    }
    void ins(pii x){
        auto it = val.lower_bound(mp(x.fi, -INF));
        if(it != val.end() && it->fi == x.fi){
            if(x.se >= it->se) return;
            delet(*it);
        }
        val.insert(x);
        vv.insert(x.se);
    }
};

string f[N];
int x[N];
int y[N];
int match[N];

void solve(myset &cur, int l, int r){
    if(l > r) return;
    int cc = l;
    while(cc <= r){
        if(f[cc] == "end."){
            cc ++ ;
            continue;
        }
        if(f[cc] == "set"){
            if(x[cc] == ban){
                cur.sum += y[cc];
            }
            else{
                auto it = cur.val.lower_bound(mp(x[cc], -INF));
                ll dp = *cur.vv.begin() + cur.sum;
                if(it != cur.val.end() && it->fi == x[cc]){
                    cur.delet(*it);
                }
                cur.sum += y[cc];
                cur.ins(mp(x[cc],dp-cur.sum));
            }
            cc ++ ;
            continue;
        }
        else{
            auto has = cur.val.lower_bound(mp(x[cc],-INF));
            if(has != cur.val.end() && has->fi == x[cc]){
                pii dd = *has;
                cur.delet(dd);
                myset uni;
                uni.sum = 0;
                uni.ins(mp(x[cc],cur.sum+(dd.se)));
                solve(uni, cc + 1, match[cc]-1);
                if(uni.val.size() > cur.val.size())
                    swap(uni,cur);
                for(auto xx : uni.val){
                    cur.ins(mp(xx.fi,xx.se+uni.sum-cur.sum));
                }
                uni.val.clear();
                uni.vv.clear();
            }
            cc = match[cc]+1;
        }
    }
}

int main(){
    fastIO;
    int n;
    cin >> n >> ban;
    vector<int> ind;
    for(int i = 1; i <= n; i ++ ){
        cin >> f[i];
        if(f[i] == "set") cin >> x[i] >> y[i];
        else if(f[i] == "if"){
            ind.push_back(i);
            cin >> x[i];
        }
        else{
            match[ind.back()] = i;
            ind.pop_back();
        }
    }
    myset init;
    init.sum = 0;
    init.ins(mp(0,0));
    init.vv.insert(0);
    solve(init, 1, n);
    cout << init.sum + *init.vv.begin() << "\n";
    return 0;
}