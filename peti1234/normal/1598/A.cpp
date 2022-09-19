#include <bits/stdc++.h>

using namespace std;
int w, n;
string a, b;
bool baj;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> a >> b;
        baj=0;
        for (int i=0; i<n; i++) {
            if (a[i]=='1' && b[i]=='1') baj=1;
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}