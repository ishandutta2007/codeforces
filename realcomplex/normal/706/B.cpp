#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j];
    }
    sort(sk,sk+n);
    int q;
    cin >> q;
    ll ans;
    for(int j = 0;j<q;j++){
        cin >> ans;
        cout << upper_bound(sk,sk+n,ans)-sk << "\n";
    }
    return 0;
}