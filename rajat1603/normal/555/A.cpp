#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
vector < int > v[N];
int n , m , sz , inp;
int ans = 1;
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= m ; ++i){
        cin >> sz;
        ans += sz - 1;
        while(sz--){
            cin >> inp;
            v[i].emplace_back(inp);
        }
    }
    ans += n;
    for(int i = 1 ; i <= m ; ++i){
        int cur = 0;
        for(int x : v[i]){
            if(x == cur + 1){
                ++cur;
            }
        }
        if(cur){
            ans -= cur << 1;
            break;
        }
    }
    cout << ans;
}