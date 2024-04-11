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

const bool multi=1;

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
        int n;
        cin>>n;
        string str,wz,res,ans;
        wz="abacaba";
        cin>>str;
        str='#'+str;
        int ile=0;
        for(int i=1;i<=n-7+1;i++)
        {
            bool b=1;
            for(int j=i;j<=i+6;j++)
            {
                if(str[j]!=wz[j-i]) b=0;
            }
            if(b) ile++;
        }
        bool is=0;
        if(ile>1) cout<<"NO"<<endl;
        else if(ile==1)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)
            {
                if(str[i]=='?') cout<<'x';
                else cout<<str[i];
            }
            cout<<endl;
        }
        else
        {
            for(int i=1;i<=n-6;i++)
            {
                bool ok=1;
                res=str;
                for(int j=i;j<=i+6;j++)
                {
                    if(str[j]=='?') res[j]=wz[j-i];
                    else if(str[j]!=wz[j-i]) ok=0;
                }
                if(ok)
                {
                    bool w=1;
                    for(int j=max((int)1,i-6);j<i;j++)
                    {
                        bool q=1;
                        for(int l=j; l<=j+6; l++)
                        {
                            if(res[l]!=wz[l-j]) q=0;
                        }
                        if(q) w=0;
                    }
                    for(int j=min((int)n-6,i+6);j>i;j--)
                    {
                        bool q=1;
                        for(int l=j; l<=j+6; l++)
                        {
                            if(res[l]!=wz[l-j]) q=0;
                        }
                        if(q) w=0;
                    }
                    if(w)
                    {
                        ans=res;
                        is=1;
                        break;
                    }
                }
            }
            if (is)
            {
                cout<<"YES"<<endl;
                for(int i=1; i<=n; i++)
                {
                    if(ans[i]=='?') cout<<'x';
                    else cout<<ans[i];
                }
                cout<<endl;
            }
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}