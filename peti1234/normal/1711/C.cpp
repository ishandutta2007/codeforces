#include <bits/stdc++.h>

using namespace std;
long long w, n, m, k, t[100005];
int main()
{
    cin >> w;
    while (w--) {
        cin >> n >> m >> k;
        for (int i=1; i<=k; i++) cin >> t[i];
        bool jo=0;
        for (int j=0; j<2; j++) {
            bool nagy=0;
            long long cnt=0;
            for (int i=1; i<=k; i++) {
                if (t[i]>=2*n) cnt+=t[i]/n;
                if (t[i]>=3*n) nagy=1;
            }
            if (cnt>=m && (nagy || m%2==0)) jo=1;
            swap(n, m);
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}