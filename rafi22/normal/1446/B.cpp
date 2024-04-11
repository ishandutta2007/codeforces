#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int DP[5007][5007];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,m,ans=0;
        cin>>n>>m;
        string str1,str2;
        cin>>str1>>str2;
        str1='#'+str1;
        str2='#'+str2;
        for(int i=1;i<str1.size();i++)
        {
            for(int j=1;j<str2.size();j++)
            {
                if(str1[i]==str2[j]) DP[i][j]=max((int)0,DP[i-1][j-1])+2;
                else DP[i][j]=max(max(DP[i-1][j],DP[i][j-1]),(int)0)-1;
                ans=max(ans,DP[i][j]);
            }
        }
        cout<<ans;
    }

    return 0;
}