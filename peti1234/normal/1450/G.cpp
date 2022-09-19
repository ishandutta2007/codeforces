
#include <bits/stdc++.h>

using namespace std;
const int c=1050002, k=32;
int m, n, xx, yy, inv[k], id[k], db[c], kezd[c], veg[c], jo[c], ert;
bool t[c];
string s;
vector<char> sol;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> xx >> yy >> s;
    for (int i=0; i<m; i++) {
        int x=s[i]-'a', z=id[x], y=(1<<(z-1));
        if (!z) {
            n++, z=n, y=(1<<(z-1)), id[x]=n;
            jo[y]=y, inv[z]=x, kezd[y]=i+1;
        }
        veg[y]=i+1, db[y]++;
    }
    t[0]=1, jo[0]=(1<<n), kezd[0]=m, ert=(1<<n)-1;
    for (int i=1; i<=ert; i++) {
        int l=(i&(-i));
        kezd[i]=min(kezd[i-l], kezd[l]);
        veg[i]=max(veg[i-l], veg[l]);
        db[i]=(db[i-l]+db[l]);
        t[i]=xx*(veg[i]-kezd[i]+1)<=db[i]*yy;
        int sum=0, sp=0;
        for (int j=0; j<n; j++) {
            int p=(1<<j);
            if (i&p) {
                sum+=p;
                if (jo[i-sum] && jo[sum]) {
                    if (t[i-sum]) sp|=jo[sum];
                    if (t[sum]) sp|=jo[i-sum];
                }
                if (jo[i-p] && jo[p]) {
                    if (t[i-p]) sp|=jo[p];
                    if (t[p]) sp|=jo[i-p];
                }

            }
        }
        jo[i]|=sp;
    }
    for (int i=1; i<=n; i++) {
        int y=1<<(i-1);
        if (jo[ert] & y) {
            sol.push_back('a'+inv[i]);
        }
    }
    cout << sol.size() << " ";
    sort(sol.begin(), sol.end());
    for (char x:sol) cout << x << " ";
    cout << "\n";
    return 0;
}