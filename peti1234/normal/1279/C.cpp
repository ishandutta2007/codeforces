#include <bits/stdc++.h>

using namespace std;
int w, n, m, maxi;
long long sum;
int t[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        maxi=0, sum=0;
        cin >> n >> m;
        sum=m;
        for (int i=1; i<=n; i++) {
            int x;
            cin >> x;
            t[x]=i;
        }
        for (int i=1; i<=m; i++) {
            int x;
            cin >> x;
            if (t[x]>maxi) sum+=2*(t[x]-i), maxi=t[x];
        }
        cout << sum << "\n";
    }
    return 0;
}