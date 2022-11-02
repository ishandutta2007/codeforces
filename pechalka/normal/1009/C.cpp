#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;
    long long max = 0, min = n * (n - 1) / 2;
    for (long long i = 1; i <= n; ++i){
        long long a = (n - i) * (n - i + 1) / 2 + i * (i - 1) / 2;
        if (a < min)
            min = a;
        if (a > max)
            max = a;
    }
    long long sum = 0;
    for (long long i = 0; i < m; ++i){
        long long x, d;
        cin >> x >> d;
        sum += x * n;
        if (d >= 0)
            sum += d * max;
        else
            sum += d * min;
    }
    double ans = sum * 1.0 / n;
    cout.precision(15);
    cout << ans;
    return 0;
}