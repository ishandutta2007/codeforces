#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int t;
int n , k;
string arr[3];
int dp[N][3];
bool solve(int pos , int row){
    if(row < 0 || row > 2){
        return 0;
    }
    if(pos > n){
        return 1;
    }
    int tm = pos - 1;
    if(pos + tm + tm <= n && arr[row][tm + tm + pos] != '.'){
        return 0;
    }
    if(dp[pos][row] != -1){
        return dp[pos][row];
    }
    //cout << pos << " " << row << " " << pos + tm + tm << endl;
    //cout << pos << " " << row << " " << pos + tm + tm + 1 << endl;
    bool b = 0;
    if(row - 1 >= 0){
        if(tm + tm + pos + 1 > n || arr[row - 1][tm + tm + pos + 1] == '.'){
            b |= solve(pos + 1 , row - 1);
        }
    }
    if(tm + tm + pos + 1 > n || arr[row][tm + tm + pos + 1] == '.'){
        b |= solve(pos + 1 , row);
    }
    else{
        return dp[pos][row] = 0;
    }
    if(row + 1 <= 2){
        if(tm + tm + pos + 1 > n || arr[row + 1][tm + tm + pos + 1] == '.'){
            b |= solve(pos + 1 , row + 1);
        }
    }
    return dp[pos][row] = b;
}
int main(){
    cin >> t;
    while(t--){
        memset(dp , -1 , sizeof(dp));
        cin >> n >> k;
        for(int i = 0 ; i < 3 ; ++i){
            cin >> arr[i];
            arr[i] = " " + arr[i];
        }
        for(int i = 0 ; i < 3 ; ++i){
            if(arr[i][1] == 's'){
                arr[i][1] = '.';
                puts(solve(1 , i) ? "YES" : "NO");
                break;
            }
        }
    }
}