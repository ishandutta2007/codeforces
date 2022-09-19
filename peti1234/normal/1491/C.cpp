#include <bits/stdc++.h>

using namespace std;
const int c=5002;
long long w, n, t[c], kov[c], sum, o=0, e=1;
void solve(int a) {
    int b=a+t[a];
    t[a]=max(t[a]-1, e);
    if (b<=n && kov[b]<=n) {
        solve(kov[b]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        kov[n+1]=n+1;
        sum=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        for (int i=1; i<=n; i++) {
            for (int j=n; j>=1; j--) {
                if (t[j]>1) {
                    kov[j]=j;
                } else {
                    kov[j]=kov[j+1];
                }
            }
            sum+=max(o, t[i]-n);
            t[i]=min(t[i], n);
            while (t[i]>1) {
                sum++;
                solve(i);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
/*
1
10
1000000000
1000000000
1000000000
1000000000
1000000000
1000000000
1000000000
1000000000
1000000000
1000000000
*/