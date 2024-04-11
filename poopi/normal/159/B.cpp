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

int n, m;
int cnt[1010][2];
int mark[1010][1010][2];

int main(){
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cnt[b][0]++;
        mark[b][a][0]++;
    }
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cnt[b][1]++;
        mark[b][a][1]++;
    }
    int t = 0, k = 0;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++)
            k += min(mark[i][j][0], mark[i][j][1]);
        t += min(cnt[i][0], cnt[i][1]);
    }
    cout << t << ' ' << k << endl;
    return 0;
}