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

int a,b,c,d;
bool flag=0;

int calc(int n)
{
    if((n-1)*n/2*b>1e12) flag=1;
    return n*a-(n-1)*n/2*b*d;
}

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

        cin>>a>>b>>c>>d;
        if(a>b*c) cout<<-1<<endl;
        else
        {
            int l=1,p=1000000,sr,ans=0;
            while(l<=p)
            {
                sr=(l+p)/2;
                //cout<<sr<<endl;
                flag=0;
                int res1=calc(sr),res2=calc(sr+1);
                //cout<<res1<<" "<<res2<<endl;
                if(res1>=res2||flag)
                {
                    p=sr-1;
                    if(!flag)
                        ans=max(ans,res1);
                }
                else
                {
                    l=sr+1;
                    ans=max(ans,res2);
                }
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}