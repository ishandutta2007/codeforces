#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[100002];
ll b[100002], c[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll n, q, k;
    cin >> n >> q >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    a[n+1] = k;
    for(int i=1;i<=n;i++){
        b[i] = a[i] - a[i-1] - 1;
        c[i] = a[i+1] - a[i] - 1;
        b[i] += b[i-1];
        c[i] += c[i-1];
    }

    for(int i=1;i<=q;i++){
        ll l, r;
        cin >> l >> r;
        cout << (b[r] - b[l] + c[r-1] - c[l-1] + a[l] - 1 + k - a[r]) << "\n";
    }
}