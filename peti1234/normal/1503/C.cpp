#include <bits/stdc++.h>

using namespace std;
long long sum, n, o=0;
vector<long long> x, y;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long a, b;
        cin >> a >> b;
        x.push_back(a), y.push_back(a+b);
        sum+=b;
    }
    sort(x.begin(), x.end()), sort(y.begin(), y.end());
    for (int i=1; i<n; i++) {
        sum+=max({o, x[i]-y[i-1]});
    }
    cout << sum << "\n";
    return 0;
}