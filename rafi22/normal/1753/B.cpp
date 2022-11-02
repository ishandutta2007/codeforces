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

int a[500007];

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
        int n,x,c;
        cin>>n>>x;
        for(int i=1;i<=n;i++)
        {
            cin>>c;
            a[c]++;
        }
        bool ok=1;
        for(int i=1;i<x;i++)
        {
            a[i+1]+=a[i]/(i+1);
            a[i]%=(i+1);
            if(a[i]) ok=0;
        }
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}