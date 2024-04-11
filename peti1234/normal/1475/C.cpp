#include <bits/stdc++.h>

using namespace std;
const int c=200002;
long long w, a, b, n, x[c], y[c], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> a >> b >> n;
        ans=n*(n-1)/2;
        for (int i=1; i<=max(a, b); i++) {
            x[i]=y[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int s; cin >> s;
            x[s]++;
        }
        for (int i=1; i<=n; i++) {
            int s; cin >> s;
            y[s]++;
        }
        for (int i=1; i<=a; i++) {
            ans-=x[i]*(x[i]-1)/2;
        }
        for (int i=1; i<=b; i++) {
            ans-=y[i]*(y[i]-1)/2;
        }
        //cout << "valasz ";
        cout << ans << "\n";
    }
    return 0;
}