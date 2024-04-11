#include <bits/stdc++.h>

using namespace std;
long long w, n;
vector<long double> sz;
long double sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            sz.push_back(x);
            sum+=x;
        }
        sort(sz.begin(), sz.end());
        cout.precision(20);
        cout << sz[n-1]+(sum-sz[n-1])/(n-1) << "\n";
        sz.clear();
        sum=0;
    }
    return 0;
}