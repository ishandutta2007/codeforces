#include <bits/stdc++.h>

using namespace std;
long long n, mini=1e18, t[100002], po, sum;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    sort(t+1, t+n+1);
    for (int i=1; i<=4e4; i++) {
        po=1, sum=0;
        for (int j=1; j<=n; j++) {
            if (po>1e14) {
                sum=1e18;
                break;
            }
            sum+=abs(t[j]-po);
            po*=i;
        }
        mini=min(mini, sum);
    }
    cout << mini << "\n";
    return 0;
}