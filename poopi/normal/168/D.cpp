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

int n, k, ini;
int p[210];
vector <P> bg;
vector <int> pr;
double dp[210][210];
bool mark[210][210];
double eh[210][210][210];
bool vis[210][210][210];

double mem(int idx, int rem){
    if(rem < 0)
        return 0;
    if(idx == pr.size())
        return (rem == 0 ? 1 : 0);
    if(mark[idx][rem])
        return dp[idx][rem];
    mark[idx][rem] = true;
    return dp[idx][rem] = (pr[idx] * mem(idx + 1, rem - 1) + (100 - pr[idx]) * mem(idx + 1, rem)) / 100.;
}

double calc(int idx, int rem, int vol){
    if(rem == 0 && vol == 0)
        return 1;
    if(idx == bg.size())
        return 0;
    if(vis[idx][rem][vol])
        return eh[idx][rem][vol];
    vis[idx][rem][vol] = true;
    double tmp = calc(idx + 1, max(0, rem - 1), max(0, vol - bg[idx].second));
    return eh[idx][rem][vol] = (bg[idx].first * tmp + (100 - bg[idx].first) * calc(idx + 1, rem, vol)) / 100.;
}

int main(){
    cin >> n >> k >> ini;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == -1)
            pr.push_back(p[i]);
        else bg.push_back(P(p[i], x));
    }
    double res = 0;
    for(int i = 0; i <= pr.size(); i++)
        res += mem(0, i) * calc(0, max(0, k - i), max(0, i - ini));
    cout << setprecision(9) << fixed << showpoint << res << endl;
    return 0;
}