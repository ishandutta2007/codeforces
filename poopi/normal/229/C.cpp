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

int64 n, m;
int64 deg[1000010];

int main(){
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        deg[a - 1]++;
        deg[b - 1]++;
    }
    int64 res = 0;
    for(int i = 0; i < n; i++)
        res += deg[i] * (n - 1 - deg[i]);
    cout << n * (n - 1) * (n - 2) / 6 - res / 2 << endl;
    return 0;
}