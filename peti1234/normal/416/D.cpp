#include <bits/stdc++.h>

using namespace std;
long long n, ans=1, t[200005], kezd=1, pos, pos2, dif;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        bool baj=0;
        if (pos2) {
            long long cel=t[pos]+dif*(i-pos);
            if (t[i]!=-1 && t[i]!=cel || cel<=0) baj=1;
        } else {
            if (t[i]==-1) continue;
            else {
                if (!pos) pos=i;
                else {
                    pos2=i;
                    dif=(t[pos2]-t[pos])/(pos2-pos);
                    if (dif*(pos2-pos)!=(t[pos2]-t[pos]) || t[pos]-(pos-kezd)*dif<=0) baj=1;
                }
            }
        }
        if (baj) {
            //cout << "baj " << i << "\n";
            ans++;
            kezd=i;
            pos=0, pos2=0;
            if (t[i]!=-1) pos=i;
        }
    }
    cout << ans << "\n";
    return 0;
}
/*
9
8 6 4 2 1 4 7 10 2
*/