#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<int> v;
    for (int i=0; i<n; i++) {
        int bb = i*k+b;
        int l = abs(bb - a);
        v.push_back(n*k/__gcd(l, n*k));

        bb = (i+1)*k-b;
        l = abs(bb - a);
        v.push_back(n*k/__gcd(l, n*k));
    }

    sort( v.begin(), v.end() );
    cout << v.front() << " " << v.back();

    return 0;
}/*

*/