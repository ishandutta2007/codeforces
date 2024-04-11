#include <bits/stdc++.h>

using namespace std;
const int c=300005;
long long n, k, ans[c], t[c], sum, cnt, maxi, o=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    for (int i=n; i>=1; i--) {
        //cout << "sum " << sum << "\n";
        t[i]-=sum;
        if (i>=k) {
            int s=i-k+1;
            ans[s]=max(o, (t[i]+k-1)/k);
            t[i]-=ans[s]*k;
            sum+=ans[s]*k;
            cnt+=ans[s];
        }
        sum-=cnt;
        cnt-=ans[i];
    }
    sum=0;
    for (int i=1; i<=n; i++) {
        //cout << "fontos " << t[i] << "\n";
        sum+=ans[i];
        //cout << ans[i] << " " << t[i] << "\n";
        maxi=max(maxi, (t[i]+i-1)/i);
    }
    //cout << maxi << "\n";
    cout << sum+maxi << "\n";
    return 0;
}