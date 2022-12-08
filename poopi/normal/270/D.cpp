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
int col[5010];
int dp[5010][5010];

int mem(int idx, int st){
    if(idx == n)
        return 0;
    if(dp[idx][st] != -1)
        return dp[idx][st];
    int &ref = dp[idx][st];
    if(col[idx] < st)
        return ref = mem(idx + 1, st) + 1;
    else if(col[idx] == st)
        return ref = mem(idx + 1, st);
    else return ref = min(mem(idx + 1, st) + 1, mem(idx + 1, col[idx]));
}

int main(){
    cin >> n >> m;
    double a;
    for(int i = 0; i < n; i++)
        cin >> col[i] >> a;
    memset(dp, -1, sizeof dp);
    cout << mem(0, 1) << endl;
    return 0;
}