#include <bits/stdc++.h>

using namespace std;
long long w, n, t[100005], ans[100005], sum, ut;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        ut=t[n];
        if (ut<0) {
            for (int i=1; i<=n; i++) {
                t[i]*=-1;
            }
            ut*=-1;
        }
        for (int i=1; i<n; i++) {
            long long ert=((t[i]<0)==(sum>=0) ? ut : -ut);
            ans[i]=ert;
            sum+=t[i]*ert;
        }
        ans[n]=-sum/ut;
        if (sum==0) {
            for (int i=1; i<n; i++) {
                ans[i]/=ut;
            }
            if (ans[n-1]>0) {
                ans[n-1]+=ut;
                ans[n]-=t[n-1];
            } else {
                ans[n-1]-=ut;
                ans[n]+=t[n-1];
            }
        }
        for (int i=1; i<=n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        sum=0, ut=0;
    }
    return 0;
}