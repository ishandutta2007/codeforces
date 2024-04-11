#include <bits/stdc++.h>

using namespace std;
int n, x, p;
vector<int> v;
int gcd(int a, int b) {
    if (a>b) swap(a, b);
    if (!a) return b;
    return gcd(a, b%a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i=1; i<n; i++) p=gcd(p, v[i]-v[i-1]);
    cout << (v[n-1]-v[0])/p+1-n << "\n";
    return 0;
}