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
#define PLL pair<int64, int64>


int main(){
    int n, m;
    cin >> n >> m;
    cout << n + m - 1 << endl;
    for(int i = 1; i <= m; i++)
        cout << 1 << ' ' << i << endl;
    for(int i = 2; i <= n; i++)
        cout << i << ' ' << m << endl;
    return 0;
}