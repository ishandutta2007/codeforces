#include "bits/stdc++.h"
using namespace std;
int n , m , inp;
int cnt[105] = {0};
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= m ; ++i){
        int mn = -1;
        int idx = -1;
        for(int j = 1 ; j <= n ; ++j){
            cin >> inp;
            if(inp > mn){
                mn = inp;
                idx = j;
            }
        }
        cnt[idx]++;
    }
    int val = -1;
    int ans = -1;
    for(int i = 1 ; i <= n ; ++i){
        if(cnt[i] > val){
            val = cnt[i];
            ans = i;
        }
    }
    cout << ans;
}