#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10, inf = 2e9 + 1;

int n, m, a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    int sum = 1;
    for (int i = 0; i < n; i++)
        cin >> a[i], sum = sum * a[i] / __gcd(sum, a[i]);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int ans = 0;
    for (int i = 0; i < sum; i++){
        bool is = 0;
        for (int j = 0; j < n && !is; j++)
            if (i % a[j] == b[j])
                is = 1;
        if (is)
            ans++;
    }
    cout << setprecision(10) << (double)ans / sum;
}