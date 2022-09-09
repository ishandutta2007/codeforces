#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")


#define ui long long
const int N = 2222; 
int n, k;
int a[N];
int dp[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    // n = 2000, k = 100;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ui l = -1, r = (ui) 2000000000 + 100;
    while (r - l > 1) {
        ui m = (l+r)>>1;
        for (int i = 0; i < n; i++) {
            dp[i] = i;
            for (int last = 0; last < i; last++) {
                int dist = (a[i] - a[last]);
                if (dist < 0 )
                    dist = -dist;
                if (m == 0) {
                    if (dist == 0) {
                        dp[i] = min(dp[i], dp[last] + (i - last - 1));
                    }
                } else {
                    int cnt = 1 + (dist - 1) / m;
                    int free_c = i - last;
                    if (cnt <= free_c) {
                        if (dp[i] > free_c-1+dp[last]) {
                            dp[i] = free_c - 1+dp[last];
                        }
                    }
                }
                
            }
        }
        bool ok = false;
        for (int last = 0; last < n; last++)
            if (dp[last] + (n - last - 1) <= k) {
                ok = true;
                break;
            }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}