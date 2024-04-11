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

int n;
int num[1010];
int way[1010][3010];
int dp[1010][3010];

int mem(int idx, int bef){
    if(idx == n)
        return 0;
    if(dp[idx][bef] != -1)
        return dp[idx][bef];
    int &ref = dp[idx][bef];
    ref = (num[idx] >= bef && num[idx] <= 2011 ? mem(idx + 1, num[idx]) : Inf);
    way[idx][bef] = num[idx];
    for(int i = 0, p = 1; i < 4; i++, p *= 10){
        int dig = (num[idx] / p) % 10;
        int x = num[idx] - dig * p;
        for(int d = 0; d < 10; d++){
            int nx = x + d * p;
            if(nx >= bef && nx <= 2011 && ref > mem(idx + 1, nx) + 1){
                ref = mem(idx + 1, nx) + 1;
                way[idx][bef] = nx;
            }
        }
    }
    return ref;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> num[i];
    memset(dp, -1, sizeof dp);
    if(mem(0, 1000) == Inf){
        cout << "No solution" << endl;
        return 0;
    }
    int bef = 1000;
    for(int i = 0; i < n; i++){
        cout << way[i][bef] << endl;
        bef = way[i][bef];
    }
    return 0;
}