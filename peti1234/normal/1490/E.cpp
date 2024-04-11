#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, n, t[c], s[c], pos, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            s[i]=t[i];
        }
        sort(s+1, s+n+1);
        pos=sum=0;
        for (int i=1; i<=n; i++) {
            if (s[i]>sum) {
                pos=i;
            }
            sum+=s[i];
        }
        cout << n-pos+1 << "\n";
        for (int i=1; i<=n; i++) {
            if (t[i]>=s[pos]) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}