#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

long long n;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    long long res = 0;
    long long x = 1;
    while(1) {
        long long sum = x * (x + 1)  * 3 / 2 - x;
        if(sum > n) break;
        long long cl = n - sum;
        res += (cl % 3 == 0);
        x++;
    }
    cout << res;
    return 0;
}