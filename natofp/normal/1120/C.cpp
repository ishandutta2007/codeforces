#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int nax=5005;

int dp[nax];

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

vector<int> maxx(vector<int> a)
{
    int n=a.size();
    vector<int> res(n,0);
    res[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        res[i]=max(res[i+1],a[i]);
    }
    return res;
}

int main()
{
    int n,a,b; cin>>n>>a>>b;
    string s; cin>>s;
    s='0'+s;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        string t="";
        for(int j=i;j>=1;j--)
        {
            t+=s[j];
        }
        vector<int> res=z_function(t);
        vector<int> pre=maxx(res);
        dp[i]=dp[i-1]+a;
        for(int j=1;j<i;j++)
        {
            int naj=pre[j];
            if(naj>=j)
            {
                dp[i]=min(dp[i],dp[i-j]+b);
            }
        }
    }
    cout<<dp[n];
    return 0;
}