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

int dp[2010], n;
int p[2010];

int mem(int idx){
    if(dp[idx] != -1)
        return dp[idx];
    if(p[idx] == -2)
        return dp[idx] = 1;
    return dp[idx] = mem(p[idx]) + 1;
}

int main(){
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> p[i];
            p[i]--;
        }
        memset(dp, -1, sizeof dp);
        int mx = 0;
        for(int i = 0; i < n; i++)
            mx = max(mx, mem(i));
        cout << mx << endl;
    }
    return 0;
}