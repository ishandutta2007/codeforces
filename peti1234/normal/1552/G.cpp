#include <bits/stdc++.h>

using namespace std;
const int c=11, c2=41;
int n, k, uj[c], mul=1, cnt;
bool v[c2];
long long po[c2], ert[c2], s[c][c2];
int main()
{
    cin >> n >> k;
    po[0]=1;
    for (int i=1; i<n; i++) {
        po[i]=po[i-1]*2;
    }
    for (int i=1; i<=k; i++) {
        int x;
        cin >> x;
        for (int j=1; j<=x; j++) {
            int y;
            cin >> y;
            y--;
            if (!v[y]) {
                v[y]=1;
                uj[i]++;
                cnt++;
            }
            s[i][j]=s[i][j-1]+po[y];
        }
        ert[i]=s[i][x];
        mul*=(uj[i]+1);
    }
    if (n>1 && cnt!=n) {
        cout << "REJECTED\n";
        return 0;
    }
    for (int mask=0; mask<mul; mask++) {
        int val=mask;
        long long ans=0;
        for (int i=1; i<=k; i++) {
            int rem=val%(uj[i]+1);
            val/=(uj[i]+1);
            long long uj=ans-(ans&ert[i]), db=__builtin_popcountll(ans&ert[i])+rem;
            ans=uj+s[i][db];
        }
        if (ans & (ans+1)) {
            cout << "REJECTED\n";
            return 0;
        }
    }
    cout << "ACCEPTED\n";
    return 0;
}