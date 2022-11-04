#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

int v[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(i = 1; i <= n; i++)
        cin >> v[i];
    long long ans = 0, sum = 0;
    for(i = 1; i <= n; i++) {
        sum += v[i];
        if(i >= k) {
            sum -= v[i - k];
            ans += sum;
        }
    }
    cout << setprecision(20) << (double)(1.0 * ans / (1.0 * (n - k + 1)));
    //cin.close();
    //cout.close();
    return 0;
}