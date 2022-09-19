#include <bits/stdc++.h>

using namespace std;
string a, b;
int w, sa, sb, jo;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> a >> b;
        sa=a.size(), sb=b.size(), jo=0;
        for (int kezd=0; kezd<sa; kezd++) {
            for (int jobb=0; kezd+jobb<sa; jobb++) {
                int bal=sb-1-jobb;
                if (bal<0 || kezd+jobb-bal<0) {
                    continue;
                }
                bool baj=0;
                for (int i=kezd; i<=kezd+jobb; i++) {
                    if (a[i]!=b[i-kezd]) {
                        baj=1;
                    }
                }
                for (int i=kezd+jobb-1; i>=kezd+jobb-bal; i--) {
                    if (a[i]!=b[jobb+kezd+jobb-i]) {
                        baj=1;
                    }
                }
                if (!baj) {
                    jo=1;
                }
            }
        }
        cout << (jo ? "YES" : "NO") << "\n";
    }
    return 0;
}