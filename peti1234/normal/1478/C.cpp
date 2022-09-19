#include <bits/stdc++.h>

using namespace std;
long long w, n, x, sum;
bool baj;
vector<long long> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n, n*=2;
        sum=baj=0, sz.clear();
        for (int i=0; i<n; i++) {
            cin >> x;
            sz.push_back(x);
        }
        sort(sz.rbegin(), sz.rend());
        for (int i=1; i<n; i+=2) {
            if (sz[i]!=sz[i-1] || sz[i]%2 || sz[i]<=sum) {
                baj=1;
            }
            if (i>1 && sz[i]==sz[i-3]) {
                baj=1;
            }
            sz[i]-=sum;
            if (sz[i]%(2*(n/2-i/2))) {
                baj=1;
            }
            sum+=sz[i]/(n/2-i/2);
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}