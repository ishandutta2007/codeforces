#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int w, t[c], db[c], invdb[c], n, sum, ans, maxi;
void cl(int a) {
    int b=db[a];
    invdb[b]--, invdb[b-1]++;
    if (b==maxi && invdb[b]==0) maxi--;
    db[a]--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n;
        ans=0, maxi=0, sum=2*n;
        for (int i=0; i<=2*n; i++) {
            db[i]=0, invdb[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int x; cin >> x;
            t[i]=x, db[x]+=2;
        }
        for (int i=1; i<=n; i++) {
            invdb[db[i]]++;
            maxi=max(maxi, db[i]);
        }
        for (int i=2; i<=n; i++) {
            int x=t[i-1], y=t[i];
            if (x!=y) {
                if (db[x]==maxi || db[y]==maxi || sum-2*maxi>=0) {
                    sum-=2, ans++;
                    cl(x), cl(y);
                }
            }
        }
        if (sum-2*maxi<-2) {
            cout << -1 << "\n";
        } else {
            cout << n-1-ans << "\n";
        }
    }
    return 0;
}