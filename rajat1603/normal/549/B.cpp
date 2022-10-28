#include "bits/stdc++.h"
using namespace std;
const int N = 101;
int arr[N];
bool v[N][N];
int cur[N] = {0};
int n;
char c;
set < int > ans;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        ans.insert(i);
        for(int j = 1 ; j <= n ; ++j){
            cin >> c;
            v[i][j] = c - '0';
            if(v[i][j]){
                cur[j]++;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    bool ok = 1;
    while(ok){
        ok = 0;
        for(int i = 1 ; i <= n ; ++i){
            if(cur[i] == arr[i]){
                ok = 1;
                cur[i]--;
                ans.erase(i);
                for(int j = 1 ; j <= n ; ++j){
                    if(v[i][j]){
                        cur[j]--;
                    }
                }
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto it : ans){
        cout << it << " ";
    }
}