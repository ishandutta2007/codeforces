#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
//#define endl '\n'
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

int n;
int ans[107];

int ask(vector<int>a)
{
    cout<<"? ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    int x;
    cin>>x;
    return x;
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
        cin>>n;
        int last=1;
        for(int i=n;i>1;i--)
        {
            vector<int>x(n,i);
            x[n-1]=1;
            if(ask(x))
            {
                last=i;
                break;
            }
        }
        ans[n]=last;
        for(int i=1;i<last;i++)
        {
            vector<int>x(n,last-i+1);
            x[n-1]=1;
            ans[ask(x)]=i;
        }
        for(int i=last+1;i<=n;i++)
        {
            vector<int>x(n,1);
            x[n-1]=i-last+1;
            ans[ask(x)]=i;
        }
        cout<<"! ";
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}