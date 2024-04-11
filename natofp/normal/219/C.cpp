#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=5e5+5;
int dp[N][33];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k; cin>>n>>k;
    string s; cin>>s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            dp[i][j]=1e9;
        }
    }
    for(int i=0;i<k;i++)
    {
        char x='A'+i;
        if(x==s[0]) dp[0][i]=0;
        else dp[0][i]=1;
    }
    for(int i=1;i<n;i++)
    {
        vector<pair<int,int> > a;
        for(int j=0;j<k;j++) a.push_back({dp[i-1][j],j});
        sort(a.begin(),a.end());
        for(int j=0;j<k;j++)
        {
            char x='A'+j;
            int naj1,naj2;
            int char1,char2;
            naj1=a[0].first;
            char1=a[0].second;
            naj2=a[1].first;
            char2=a[1].second;
            if(j!=char1)
            {
                int val=dp[i-1][char1];
                if((j+'A')!=s[i]) val++;
                dp[i][j]=min(dp[i][j],val);
            }
            else
            {
                int val=dp[i-1][char2];
                if((j+'A')!=s[i]) val++;
                dp[i][j]=min(dp[i][j],val);
            }

        }
    }

    char last='x';
    string res="";
    int ans=1e9;
    for(int i=0;i<k;i++) ans=min(ans,dp[n-1][i]);
    cout<<ans<<endl;
    for(int i=n-1;i>=0;i--)
    {
        int idx=-1;
        int naj=1e9;
        for(int j=0;j<k;j++)
        {
            if((j+'A')!=last)
            {
                if(dp[i][j]<naj)
                {
                    naj=dp[i][j];
                    idx=j;
                }
            }
        }
        res+=('A'+idx);
        last='A'+idx;
    }
    for(int i=n-1;i>=0;i--) cout<<res[i];
    return 0;
}