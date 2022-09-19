#include <bits/stdc++.h>

using namespace std;
int db[8002], kom[8002], n, ans, w;
bool v[8002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n, ans=0;
        for (int i=1; i<=n; i++) db[i]=0, kom[i]=0, v[i]=0;
        for (int i=1; i<=n; i++) cin >> kom[i], db[kom[i]]++, kom[i]+=kom[i-1];
        for (int i=0; i<n; i++) for (int j=i+2; j<=n; j++) {
            int x=kom[j]-kom[i];
            if (x<=n) v[x]=1;
        }
        for (int i=1; i<=n; i++) ans+=v[i]*db[i];
        cout << ans << "\n";
    }
    return 0;
}