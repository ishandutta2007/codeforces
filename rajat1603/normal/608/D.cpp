#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n;
int arr[N];
bool pal[N][N];
int mem[N][N];
int solve(int l , int r){
    if(r < l){
        return 0;
    }
    if(pal[l][r]){
        return 1;
    }
    if(mem[l][r] != -1){
        return mem[l][r];
    }
    int res = INT_MAX;
    for(int i = l ; i < r ; ++i){
        res = min(res , solve(l , i) + solve(i + 1 , r));
    }
    if(arr[l] == arr[r]){
        res = min(res , solve(l + 1 , r - 1));
    }
    //cout << l << " " << r << " " << res << endl;
    return mem[l][r] = res;
}
int main(){
    cin >> n;
    memset(mem , -1 , sizeof(mem));
    memset(pal , 0 , sizeof(pal));
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        pal[i][i] = 1;
    }
    for(int i = 2 ; i <= n ; ++i){
        for(int j = 1 ; j + i - 1 <= n ; ++j){
            if(arr[j] == arr[j + i - 1]){
                if(i == 2){
                    pal[j][j + i - 1] = 1;
                }
                else{
                    pal[j][j + i - 1] = pal[j + 1][j + i - 2];
                }
            }
        }
    }
    cout << solve(1 , n);
}