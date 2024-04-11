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

int n;
P a[1010];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    reverse(a, a + n);
    int rem = 1, p = 0, cnt = 0;
    while(p < n && rem > 0){
        cnt += a[p].second;
        rem += a[p].first - 1;
        p++;
    }
    cout << cnt << endl;
    return 0;
}