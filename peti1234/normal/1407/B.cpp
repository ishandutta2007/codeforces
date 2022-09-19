#include <bits/stdc++.h>

using namespace std;
int w, t[1002], n, maxi, ert=0, pos;
bool v[1002];
void add(int a) {
    cout << t[a] << " ";
    v[a]=true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w, t[0]=1;
    while(w--) {
        cin >> n, pos=1;
        for (int i=1; i<=n; i++) {
            cin >> t[i], v[i]=0;
            if (t[i]>t[pos]) pos=i;
        }
        add(pos), maxi=t[pos];
        for (int i=1; i<n; i++) {
            ert=1, pos=0;
            for (int j=1; j<=n; j++) {
                if (!v[j] && __gcd(maxi, t[j])>=ert) pos=j, ert=__gcd(maxi, t[j]);
            }
            add(pos), maxi=ert;
        }
        cout << "\n";
    }
    return 0;
}