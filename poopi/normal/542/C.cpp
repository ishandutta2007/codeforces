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
int adj[210];
int64 lst;
int64 dist[210];
vector <int64> mul;

int64 gcd(int64 a, int64 b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> adj[i];
        adj[i]--;
    }
    for(int i = 0; i < n; i++){
        memset(dist, -1, sizeof dist);
        int idx = i, pnt = 0;
        dist[idx] = 0;
        while(dist[adj[idx]] == -1){
            dist[adj[idx]] = ++pnt;
            idx = adj[idx];
        }
        int64 mn = dist[adj[idx]];
        lst = max(lst, mn);
        mul.push_back(pnt - mn + 1);
    }
    int64 d = 1;
    for(int i = 0; i < mul.size(); i++)
        d = d / gcd(d, mul[i]) * mul[i];

    cout << max(1LL, (lst + d - 1) / d) * d << endl;
    return 0;
}