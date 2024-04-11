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

int cnt[200];

int main(){
    int n, a;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a;
        cnt[i] = cnt[i - 1] + a;
    }
    int res = -10000;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            res = max(res, j - i + 1 - 2 * (cnt[j] - cnt[i - 1]));
    cout << res + cnt[n] << endl;
    return 0;
}