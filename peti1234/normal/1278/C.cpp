#include <bits/stdc++.h>

using namespace std;
int t[200001];
int kul[200001];
int mk[200001];
int n, q;
int main()
{
    cin >> q;
    while(q--) {
        cin >> n;
        for (int i=0; i<=2*n; i++) kul[i]=-n, mk[i]=-n;
        for (int i=1; i<=2*n; i++) cin >> t[i];
        int jel=n;
        kul[n]=0, mk[n]=0;
        for (int i=1; i<=n; i++) {
            if (t[i]==2) jel++;
            else jel--;
            kul[jel]=i;
        }
        jel=n;
        for (int i=2*n; i>=n+1; i--) {
            if (t[i]==1) jel++;
            else jel--;
            mk[jel]=2*n+1-i;
        }
        int maxi=0;
        for (int i=0; i<=2*n; i++) maxi=max(maxi, kul[i]+mk[i]);
        cout << 2*n-maxi << "\n";
    }
    return 0;
}