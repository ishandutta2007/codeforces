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

int n, a[3];
int dp[310][310];
string name[2] = {"BitAryo", "BitLGM"};

int mem(int x, int y){
    if(dp[x][y] != -1)
        return dp[x][y];
    int mn = 1;
    for(int i = 1; i <= x; i++)
        mn = min(mn, mem(x - i, y));
    for(int i = 1; i <= y; i++)
        mn = min(mn, mem(x, y - i));
    for(int i = 1; i <= min(x, y); i++)
        mn = min(mn, mem(x - i, y - i));
    return dp[x][y] = 1 - mn;
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n == 1)
        cout << name[(a[0] == 0 ? 0 : 1)] << endl;
    if(n == 2)
        cout << name[mem(a[0], a[1])] << endl;
    if(n == 3)
        cout << name[((a[0] ^ a[1] ^ a[2]) == 0 ? 0 : 1)] << endl;
    return 0;
}