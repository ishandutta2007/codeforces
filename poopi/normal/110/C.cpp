                                       /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>
int dp[1000010];

int main(){
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= 1000000; i++){
        int tmp = 1000000;
        if(i >= 4 && dp[i - 4] != -1)
            tmp = min(tmp, dp[i - 4] + 1);
        if(i >= 7 && dp[i - 7] != -1)
            tmp = min(tmp, dp[i - 7] + 1);
        if(tmp != 1000000)
            dp[i] = tmp;
    }
    int n;
    while(cin >> n){
        if(dp[n] == -1)
            cout << -1 << endl;
        else{
            int a, b;
            int t = n - 4 * dp[n];
            b = t / 3;
            a = dp[n] - b;
            for(int i = 0; i < a; i++)
                printf("4");
            for(int i = 0; i < b; i++)
                printf("7");
            printf("\n");
        }
    }
    return 0;
}