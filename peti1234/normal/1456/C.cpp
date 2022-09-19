#include <bits/stdc++.h>

using namespace std;
const int c=500002;
long long t[c], cs[c], n, k, sum, pos=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k, k++;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1), reverse(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        sum+=cs[pos], cs[pos]+=t[i];
        if (cs[0]<0) {
            pos++;
            pos%=k;
        }
    }
    cout << sum << "\n";
    return 0;
}