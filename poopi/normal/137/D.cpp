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

int n, k;
int cost[510][510];
int dp[510][510];
int way[510][510];
string str;

int pal(int s, int e){
    if(s >= e)
        return 0;
    if(cost[s][e] != -1)
        return cost[s][e];
    return cost[s][e] = pal(s + 1, e - 1) + (str[s] != str[e] ? 1 : 0);
}

int mem(int idx, int rem){
    if(idx == n)
        return 0;
    if(rem == 0)
        return Inf;
    if(dp[idx][rem] != -1)
        return dp[idx][rem];
    int &ref = dp[idx][rem];
    ref = Inf;
    for(int i = idx; i < n; i++){
        int tmp = pal(idx, i) + mem(i + 1, rem - 1);
        if(ref > tmp){
            ref = tmp;
            way[idx][rem] = i;
        }
    }
    return ref;
}

int main(){
    cin >> str >> k;
    n = str.length();
    memset(cost, -1, sizeof cost);
    memset(dp, -1, sizeof dp);
    cout << mem(0, k) << endl;
    bool fir = true;
    int idx = 0, rem = k;
    while(idx < n){
        if(!fir) cout << '+';
        fir = false;
        int s = idx, e = way[idx][rem];
        for(int i = s; i <= e; i++){
            cout << str[i];
            str[s + e - i] = str[i];
        }
        idx = way[idx][rem] + 1;
        rem--;
    }
    cout << endl;
    return 0;
}