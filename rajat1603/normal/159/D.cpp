#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 11;
string str;
int n;
bool ispal[N][N] = {0};
int sum[N] = {0};
long long ans = 0;
int main(){
    cin >> str;
    n = str.size();
    str = " " + str;
    for(int i = 1 ; i <= n ; ++i){
        int idx1 = i;
        int idx2 = i;
        while(idx1 >= 1 && idx2 <= n && str[idx1] == str[idx2]){
            ++sum[idx1];
            ispal[idx1--][idx2++] = 1;
        }
        idx1 = i;
        idx2 = i + 1;
        while(idx1 >= 1 && idx2 <= n && str[idx1] == str[idx2]){
            ++sum[idx1];
            ispal[idx1--][idx2++] = 1;
        }
    }
    for(int i = n - 1; i >= 1 ; --i){
        sum[i] += sum[i + 1];
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i ; j <= n ; ++j){
            if(ispal[i][j]){
                ans += sum[j + 1];
            }
        }
    }
    cout << ans;
}