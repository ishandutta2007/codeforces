#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
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
        int a,b,ans=inf;
        cin>>a>>b;
        ans=b-a;
        for(int i=a;i<=b;i++)
        {
            int c=0;
            for(int j=20;j>=0;j--)
            {
                if(!((1<<j)&b)&&((1<<j)&i))
                {
                    c+=1<<j;
                    break;
                }
                c+=(1<<j)&b;
            }
           // cout<<c<<" "<<(c|i)<<endl;
            ans=min(ans,i-a+1+(c|i)-b);
        }
        cout<<ans<<endl;
    }


    return 0;
}