#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 4010

using namespace std;

int n, sl;
double sum;

int main() {
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n * 2; i++) {
        double x;
        cin >> x;
        x -= (int)x;
        sum += x;
        if(x) sl++;
    }
    double res = 1111111111.0;
    for(int i = max(sl - n,0); i <= min(sl, n); i++)
    res = min(res, abs(1.0 * i - sum));
    printf("%0.3f", res);
    return 0;
}