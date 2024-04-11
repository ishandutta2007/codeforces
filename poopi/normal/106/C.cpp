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

int n, m;
int tot[20], us[20], c[20], d[20];
int dp[1010][12];

int mem(int rem, int idx){
    //cout << rem << ' ' << idx << endl;
    if(rem == 0 || idx == m)
        return 0;
    if(dp[rem][idx] != -1)
        return dp[rem][idx];
    int& ref = dp[rem][idx];
    ref = 0;
    for(int i = 0; i <= n; i++){
        if(c[idx] * i <= rem && us[idx] * i <= tot[idx]){
            int tmp = i * d[idx] + mem(rem - c[idx] * i, idx + 1);
            ref = max(tmp, ref);
        }
    }
    return ref;
}

int main(){
    while(cin >> n >> m){
        m++;
        cin >> c[0] >> d[0];
        tot[0] = n;
        us[0] = 1;
        for(int i = 1; i < m; i++)
            cin >> tot[i] >> us[i] >> c[i] >> d[i];
        memset(dp, -1, sizeof dp);
        cout << mem(n, 0) << endl;
    }
    return 0;
}