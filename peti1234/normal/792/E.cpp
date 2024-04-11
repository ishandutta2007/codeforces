#include <bits/stdc++.h>

using namespace std;
long long n, t[502], mini=1e15, ans=1e15;
void calc(int ert) {
    if (ert<=0) {
        return;
    }
    long long sum=0;
    for (int i=1; i<=n; i++) {
        if (t[i]%ert*(ert+1)>t[i]) {
            return;
        }
        long long s=(ert+1-t[i]%(ert+1))%(ert+1);
        sum+=s+(t[i]-s*ert)/(ert+1);
    }
    ans=min(ans, sum);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        mini=min(mini, t[i]);
    }
    for (int i=1; i<=sqrt(mini)+5; i++) {
        int ert=mini/i;
        calc(ert), calc(ert-1);
    }
    cout << ans << "\n";
    return 0;
}