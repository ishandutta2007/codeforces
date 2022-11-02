#include<bits/stdc++.h>

using namespace std;

const long long maxi = 1e6+10;
long long a[maxi], d[maxi];
long long mip[maxi], mis[maxi], pref[maxi];
int n, k;
pair<long long,int> c[maxi];
int main()
{
    cin>>n>>k;

    long long ans = 0;
    for (int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
        pref[i] = pref[i-1] + a[i];
    }

    for (int i = 1;i<=n;i++)
    {
        scanf("%lld",&d[i]);
        if (i==1) mip[i] = d[i]; else
            mip[i] = min(mip[i-1], d[i]);
    }

    if (k==0)
    {
        for (int i = 1;i<=n;i++)
            ans = max(ans, pref[n] - pref[i-1] - d[i]);

        cout<<ans<<endl;
        return 0;
    }


    if (k==1)
    {
        long long sum = 0;

        for (int i = 1;i<=n;i++)
            sum+=a[i];
        for (int i = 1;i<=n;i++)
        c[i] = {d[i], i};

        sort(c+1, c+n+1);

        ans = max(ans, sum - c[1].first- c[2].first);

        for (int i = 1;i<=n-1;i++)
            ans = max(ans, pref[n-1] - d[i]);

        for (int i= 2;i<=n;i++)
            ans = max(ans, pref[n] - pref[i-1] - d[i]);

        long long mi = a[n-1];
        for (int i = n-1;i>1;i--)
            mi = min(mi, a[i]);
        ans = max(ans, pref[n] - mi - d[1]);

        cout<<ans<<endl;
        return 0;
    }

    //k>=2
    ans = max(ans, pref[n] - mip[n-1]);
    ans = max(ans, a[n] - d[n]);
    cout<<ans<<endl;
    return 0;
}