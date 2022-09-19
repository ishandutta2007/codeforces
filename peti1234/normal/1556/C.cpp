#include <bits/stdc++.h>

using namespace std;
long long n, t[1005], ans;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=1; i<=n; i+=2) {
        long long mini=1, sum=1;
        for (int j=i+1; j<=n; j++) {
            if (j%2==0 && t[i]>=mini && t[j]>=sum) {
                ans+=min(t[i]-mini+1, t[j]-sum+1);
                //cout << "fontos " << i << " " << j << " " << mini << " " << sum << " " << ans << "\n";
            }
            if (j%2) {
                sum+=t[j];
            } else {
                sum-=t[j];
                if (sum<0) {
                    mini-=sum;
                    sum=0;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}