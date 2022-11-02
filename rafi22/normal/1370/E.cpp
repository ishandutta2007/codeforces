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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    if(multi)
        cin>>t;
    else t=1;
    while(t--)
    {
        int n;
        cin>>n;
        string str1,str2;
        cin>>str1>>str2;
        int res=0,act=0,s1=0,s2=0;
        for(int i=0;i<n;i++)
        {
            if(str1[i]=='1') s1++;
            if(str2[i]=='1') s2++;
            if(str1[i]!=str2[i])
            {
                if(str1[i]=='1') act++;
                else act--;
                act=max((int)0,act);
                res=max(act,res);
            }
        }
        act=0;
        for(int i=0;i<n;i++)
        {
            if(str1[i]!=str2[i])
            {
                if(str1[i]=='0') act++;
                else act--;
                act=max((int)0,act);
                res=max(act,res);
            }
        }
        if(s1!=s2) cout<<-1;
        else cout<<res;
    }

    return 0;
}