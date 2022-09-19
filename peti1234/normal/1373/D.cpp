#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, n;
long long t[c], e[c], h[c], sum, maxi, cnt, mini;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, sum=0, maxi=0, cnt=0, mini=0;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
            sum+=t[i]*(i%2);
            if (i%2) e[i/2]=t[i-1]-t[i];
            else h[i/2]=t[i]-t[i-1];
        }
        for (int i=1; i<=n/2; i++) cnt+=h[i], mini=min(mini, cnt), maxi=max(maxi, cnt-mini);
        cnt=0, mini=0;
        for (int i=1; i<=(n-1)/2; i++) cnt+=e[i], mini=min(mini, cnt), maxi=max(maxi, cnt-mini);
        cout << sum+maxi << "\n";
    }
    return 0;
}
/*
#include <bits/stdc++.h>

using namespace std;
int w;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {

    }
    return 0;
}
*/