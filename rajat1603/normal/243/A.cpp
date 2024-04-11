#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 20;
int arr[N];
int n;
int lb[LN][N];
bool ans[1 << LN] = {0};
int print = 0;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    for(int i = 0 ; i < LN ; ++i){
        lb[i][n + 1] = n + 1;
        for(int j = n ; j >= 1 ; --j){
            lb[i][j] = lb[i][j + 1];
            if(arr[j] & (1 << i)){
                lb[i][j] = j;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        int cur = arr[i];
        if(!ans[cur]){
            ++print;
            ans[cur] = 1;
        }
        int pos = i + 1;
        int mn = n + 1;
        while(pos <= n){
            mn = n + 1;
            for(int j = 0 ; j < LN ; ++j){
                if(!(cur & (1 << j))){
                    mn = min(mn , lb[j][pos]);
                }
            }
            if(mn == n + 1){
                break;
            }
            cur |= arr[mn];
            pos = mn + 1;
            if(!ans[cur]){
                ++print;
                ans[cur] = 1;
            }
        }
    }
    cout << print;
}