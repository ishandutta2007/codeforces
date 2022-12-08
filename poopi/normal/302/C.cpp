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

int n, cnt;
int sum, mn = 10000;
int s, e;

int main(){
    int a;
    cin >> n;
    for(int i = 0; i < 2 * n - 1; i++){
        cin >> a;
        if(a < 0) cnt++;
        sum += abs(a);
        mn = min(mn, abs(a));
        if(i == 0) s = abs(a);
        if(i == 2 * n - 2) e = abs(a);
    }
    if(cnt % 2 == 0 || n % 2 == 1)
        cout << sum << endl;
    else cout << sum - 2 * mn << endl;
    return 0;
}