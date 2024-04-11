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

const bool multi=0;

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
        if(n==1)
        {
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
            return 0;
        }
        int k=(n+1)/3;
        int res=n-k;
        cout<<res<<endl;
        int x=n-(n+1)%3,y=2;
        for(int i=0;i<res-(n+1)%3;i++)
        {
            cout<<x<<" "<<y<<endl;
            if(i%2==0)
            {
                x-=2;
                y++;
            }
            else
            {
                x--;
                y+=2;
            }
        }
        if((n+1)%3==1) cout<<n<<" "<<n<<endl;
        if((n+1)%3==2)
        {
            cout<<n-1<<" "<<n-1<<endl;
            cout<<n<<" "<<n<<endl;
        }
    }

    return 0;
}