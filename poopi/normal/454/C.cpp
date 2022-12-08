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

int n, m;

int main(){
    cin >> m >> n;
    //double res = m;
    //for(int i = 1; i < m; i++)
    //  res -= pow((double)i / m, n);
    double res = 0;
    for(int i = 1; i <= m; i++)
        res += i * (pow((double)i / m, n) - pow((double)(i - 1) / m, n));
    cout << setprecision(9) << fixed << res << endl;
    return 0;
}