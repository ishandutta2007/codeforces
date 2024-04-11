#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int w, n, ut;
double ke[c], ve[c], l, t[c];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> w;
    while(w--) {
        cin >> n >> l;
        for (int i=1; i<=n; i++) cin >> t[i];
        t[n+1]=l, ve[n+1]=0, ut=0;
        for (int i=1; i<=n; i++) {
            ke[i]=ke[i-1]+(t[i]-t[i-1])/i;
        }
        for (int i=n; i>=1; i--) {
            ve[i]=ve[i+1]+(t[i+1]-t[i])/(n-i+1);
        }
        for (int i=1; i<=n; i++) {
            if (ke[i]<ve[i]) ut=i;
        }
        cout.precision(20);
        if (ke[ut]<ve[ut+1]) cout << ve[ut+1]+(t[ut+1]-t[ut]-(ve[ut+1]-ke[ut])*(ut+1))/(n+2) << "\n";
        else cout << ke[ut]+(t[ut+1]-t[ut]-(ke[ut]-ve[ut+1])*(n+1-ut))/(n+2) << "\n";
    }
    return 0;
}
/*
1
5 7
1 2 3 4 6
*/