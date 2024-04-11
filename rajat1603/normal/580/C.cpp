#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
bool arr[N];
vector < int > v[N];
bool leaf[N];
void dfs(int node , int cur , int parent){
    if(cur > m){
        return;
    }
    bool b = 0;
    for(int next : v[node]){
        if(next != parent){
            b = 1;
            if(arr[next]){
                dfs(next , cur + 1 , node);
            }
            else{
                dfs(next , 0 , node);
            }
        }
    }
    leaf[node] = !b;
}
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        leaf[i] = 0;
    }
    for(int i = 1 ; i < n ; ++i){
        int a , b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(1 , arr[1] , -1);
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        ans += leaf[i];
    }
    cout << ans;
}