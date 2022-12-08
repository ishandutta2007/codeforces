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
int arr[100010];

int main(){
    cin >> n >> m;
    int cnt = 0, a, b;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a < 0) cnt++;
    }
    int t = min(cnt, n - cnt);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        if(a % 2 == b % 2 || 2 * t < b - a + 1)
            cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}