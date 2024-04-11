                                        /* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL
#define Max (1 << 22)

int n;
int arr[1000010];
bool has[Max];
int dp[Max];

int mem(int mask){
    if(mask == 0)
        return -2;
    if(dp[mask] != -1)
        return dp[mask];
    dp[mask] = (has[mask] ? mask : -2);
    for(int i = 0; i < 22; i++)
        if((mask & (1 << i)) && mem(mask - (1 << i)) != -2)
            dp[mask] = dp[mask - (1 << i)];
    return dp[mask];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        has[arr[i]] = true;
    }
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
        printf("%d ", mem(Max - arr[i] - 1) == -2 ? -1 : dp[Max - arr[i] - 1]);
    printf("\n");
    return 0;
}