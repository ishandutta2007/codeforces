#include <bits/stdc++.h>

using namespace std;
const int c=3002;
long long w, n, sum, db[c], h[c], par[c], t[c];
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, sum=0;
        for (int i=1; i<=n; i++) db[i]=0;
        for (int i=1; i<=n; i++) cin >> t[i], db[t[i]]++;
        for (int i=1; i<=n; i++) {
            sum+=db[i]*(db[i]-1)*(db[i]-2)*(db[i]-3)/24;
            for (int j=1; j<=n; j++) h[j]=0, par[j]=0;
            for (int j=1; j<=n; j++) {
                h[t[j]]++;
                if (t[j]==i) for (int k=1; k<=n; k++) par[k]+=h[k];
                else sum+=par[t[j]]*(db[i]-h[i]);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}