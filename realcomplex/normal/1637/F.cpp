#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;

set<int> T[N];
int H[N];


int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> H[i];
    }
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].insert(v);
        T[v].insert(u);
    }
    set<pii> leafs;
    for(int i = 1; i <= n; i ++ ){
        if(T[i].size() == 1){
            leafs.insert(mp(H[i], i));
        }
    }
    int current = 0;
    ll answer = 0;
    while(leafs.size() > 1){
        auto it = leafs.begin();
        answer += (it->fi - current) * 1ll * (int)leafs.size();
        current = it->fi;
        while(!leafs.empty()){
            auto xx = leafs.begin();
            if(xx->fi <= current){
                for(auto y : T[xx->se]){
                    T[y].erase(xx->se);
                    if(T[y].size() == 1){
                        leafs.insert(mp(H[y], y));
                    }
                }
                leafs.erase(xx);
            }
            else{
                break;
            }
        }
    }
    if(!leafs.empty()){
        auto it = leafs.end();
        it -- ;
        answer += 2ll * (it->fi - current);
    }
    cout << answer << "\n";
    return 0;
}