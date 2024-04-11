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

int ans[100007];

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
        int n,a,b;
        cin>>n>>a>>b;
        swap(a,b);
        if(abs(a-b)>1||a+b>n-2)
        {
            cout<<-1<<endl;
            continue;
        }
        if(a>b)
        {
            for(int i=n;i>a+b+1;i--) ans[i]=i;
            int c=1;
            for(int i=2;i<=a+b+1;i+=2) ans[i]=c++;
            for(int i=1;i<=a+b+1;i+=2) ans[i]=c++;
        }
        else if(a<b)
        {
            for(int i=n;i>a+b+1;i--) ans[i]=n-i+1;
            int c=n-a-b;
            for(int i=1;i<=a+b+1;i+=2) ans[i]=c++;
            for(int i=2;i<=a+b+1;i+=2) ans[i]=c++;
        }
        else
        {
            for(int i=n;i>a+b+1;i--) ans[i]=n-i+1;
            int c=n-a-b;
            for(int i=2;i<=a+b+1;i+=2) ans[i]=c++;
            for(int i=1;i<=a+b+1;i+=2) ans[i]=c++;
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}