#include <bits/stdc++.h>

using namespace std;
long long n, kis, nagy, ans=1;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        sz.push_back(x);
    }
    sort(sz.begin(), sz.end());
    for (int i=0; i<n; i++) {
        if (sz[i]==sz[2]) {
            if (i<=2) kis++;
            else nagy++;
        }
    }
    for (int i=nagy+1; i<=nagy+kis; i++) ans*=i;
    for (int i=1; i<=kis; i++) ans/=i;
    cout << ans << "\n";
    return 0;
}