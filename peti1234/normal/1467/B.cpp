#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int w, n, t[c], cnt, maxi;
bool jo[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        t[0]=t[1], t[n+1]=t[n];
        cnt=0, maxi=0;
        for (int i=1; i<=n; i++) {
            jo[i]=0;
            if (t[i]>max(t[i-1], t[i+1]) || t[i]<min(t[i-1], t[i+1])) {
                cnt++;
                jo[i]=1;
            }
        }
        if (cnt>0) {
            maxi=1;
        }
        for (int i=2; i<n-1; i++) {
            if (jo[i]) {
                if (jo[i-1] && jo[i] && jo[i+1]) {
                    maxi=3;
                }
                if (jo[i+1] && (i==2 || i==n-2 || abs(t[i-1]-t[i])>=abs(t[i+1]-t[i]) || abs(t[i+2]-t[i+1])>=(abs(t[i]-t[i+1])) || t[i-2]==t[i-1] || t[i+2]==t[i+3])) {
                    maxi=max(maxi, 2);
                }
            }
        }
        cout << cnt-maxi << "\n";
    }
    return 0;
}
/*
1
6
1 2 3 1 2 3
*/