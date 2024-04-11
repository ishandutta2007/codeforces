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

bool DP[1007];
int take[1007];

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
        for(int i=0;i<=n;i++)
        {
            DP[i]=0;
            take[i]=0;
        }
        DP[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(i-3>=0&&DP[i-3])
            {
                DP[i]=1;
                take[i]=3;
            }
            else if(i-5>=0&&DP[i-5])
            {
                DP[i]=1;
                take[i]=5;
            }
            else if(i-7>=0&&DP[i-7])
            {
                DP[i]=1;
                take[i]=7;
            }
        }
        if(!DP[n]) cout<<-1<<endl;
        else
        {
            int a=0,b=0,c=0,it=n;
            while(it>0)
            {
                if(take[it]==3)
                {
                    a++;
                    it-=3;
                }
                else if(take[it]==5)
                {
                    b++;
                    it-=5;
                }
                else if(take[it]==7)
                {
                    c++;
                    it-=7;
                }
            }
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }

    return 0;
}