#include <bits/stdc++.h>

using namespace std;
long long w, t[200005];
map<long long, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        long long n, sum=0, maxi=0;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i];
        }
        long long f=0;
        for (int i=1; i<=n; i++) {
            f+=t[i];
            if (2*f<=sum) {
                m[f]=i;
            }
        }
        f=0;
        for (int i=n; i>=1; i--) {
            f+=t[i];
            if (2*f<=sum) {
                if (m[f]) {
                    maxi=m[f]+n-i+1;
                }
            }
        }
        cout << maxi << "\n";
        m.clear();
    }
    return 0;
}