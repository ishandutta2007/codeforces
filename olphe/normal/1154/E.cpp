#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)
void fast_io(){ios::sync_with_stdio(false); cin.tie(nullptr);}
inline int solve(){
    int N,K; cin >> N >> K;
    vector<int>v(N);
    for(auto& e : v) cin >> e;
    set<int,greater<>>S; set<int>U;
    vector<int>pos(N + 1,-1);
    vector<int>ans(N,-1);
    rep(i,N) pos[v[i]] = i;
    rep(i,N) U.emplace(i);
    for(auto e : v) S.insert(e);
    int cnt = 0;
    while(not S.empty()){
        auto sit = S.begin();
        auto uit = U.find(pos[*sit]);
        int id = pos[*sit];
        ans[id] = (cnt % 2 == 0 ? 1 : 2);
        rep(j,K){
            if(next(uit) != U.end()){
                auto nxt = next(uit);
                ans[*nxt] = (cnt % 2 == 0 ? 1 : 2);
                S.erase(v[*nxt]);
                U.erase(nxt);
            }
        }
        rep(j,K){
            if(uit != U.begin()){
                auto prv = prev(uit);
                ans[*prv] = (cnt % 2 == 0 ? 1 : 2);
                S.erase(v[*prv]);
                U.erase(prv);
            }
        }
        U.erase(uit);
        S.erase(sit);
        ++cnt;
    }
    for(auto e : ans)cout << e;
    cout << endl;
    return 0;
}
signed main(){
    fast_io();
    int Q = 1;
    while(Q--){solve();}
}