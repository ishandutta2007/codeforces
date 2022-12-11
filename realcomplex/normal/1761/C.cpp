#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 110;
vector<int> T[N];
vector<int> res[N];
bool vis[N];

void add(int node, int ad){
    vis[node]=true;
    res[node].push_back(ad);
    for(auto x : T[node]){
        if(!vis[x])
            add(x, ad);
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
        res[i].clear();
    }
    char f;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cin >> f;
            if(f == '1'){
                T[i].push_back(j);
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ) vis[j]=false;
        add(i, i);
    }
    for(int i = 1; i <= n; i ++ ){
        cout << res[i].size() << " ";
        for(auto x : res[i]){
            cout << x << " ";
        }
        cout << "\n";
    }

}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}