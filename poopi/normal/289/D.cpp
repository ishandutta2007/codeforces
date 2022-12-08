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
#define P pair<int, double>
#define PLL pair<int64, int64>
#define Mod 1000000007LL

int n, k;

int main(){
    cin >> n >> k;
    int64 res = 1;
    for(int i = 1; i < n; i++)
        res = (res * (i < k ? k : n - k)) % Mod;
    cout << res << endl;
    return 0;
}