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

int a[200007];
int ile[30];

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
        memset(ile,0,sizeof ile);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            for(int j=29;j>=0;j--) ile[j]+=(a[i]&(1<<j))>0;
        }
        for(int i=1;i<=n;i++)
        {
            bool ok=1;
            for(int j=29;j>=0;j--) if(ile[j]%i!=0) ok=0;
            if(ok) cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}