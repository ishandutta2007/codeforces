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
P arr[1000010];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    sort(arr, arr + n);
    double l = 0, r = 1e10;
    for(int I = 0; I < 100; I++){
        double mid = (l + r) / 2;
        bool f = false;
        double mx = -1e20;
        for(int i = 0; i < n; i++){
            double t = mid * arr[i].second + arr[i].first;
            if(arr[i].second > 0)
                mx = max(mx, t);
            else if(t - 1e-9 < mx)
                f = true;
        }
        if(f) r = mid;
        else l = mid;
    }
    cout.precision(10);
    cout.setf(ios::fixed | ios::showpoint);
    cout << (r > 5 * 1e9 ? -1. : r) << endl;
    return 0;
}