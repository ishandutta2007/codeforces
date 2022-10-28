#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int t;
int n;
vector < int > v[N];
int a , b;
int ans = 0;
int farthest(int node , int prev = -1){
    int ret = 0;
    for(int next : v[node]){
        if(next != prev){
            ret = max(ret , farthest(next , node) + 1);
        }
    }
    return ret;
}
int diameter(){
    int mx = 0;
    for(int i = 1 ; i <= n ; ++i){
        mx = max(mx , farthest(i));
    }
    return mx;
}
int main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1 ; i <= n ; ++i){
            v[i].clear();
        }
        for(int i = 1 ; i < n ; ++i){
            cin >> a >> b;
            v[a].emplace_back(b);
            v[b].emplace_back(a);
        }
        ans += diameter();
    }
    cout << ans;
}