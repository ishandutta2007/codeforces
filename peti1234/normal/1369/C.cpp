#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n, k;
long long t[c], p[c], sum, f;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, sum=0, f=0;
        for (int i=1; i<=n; i++) cin >> t[i];
        for (int i=1; i<=k; i++) cin >> p[i];
        sort(t+1, t+n+1), sort(p+1, p+k+1);
        for (int i=n; i>n-k; i--) sum+=t[i];
        for (int i=1; i<=k; i++) {
            f+=p[i]-1;
            if (p[i]==1) sum+=t[n+1-i];
            else sum+=t[n-k-f+1];
        }
        cout << sum << "\n";
    }
    return 0;
}