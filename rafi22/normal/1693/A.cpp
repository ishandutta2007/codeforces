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
        int n,sum=0;
        cin>>n;
        int last=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]!=0) last=i;
            sum+=a[i];
        }
        bool ok=1;
        if(sum!=0) ok=0;
        if(last>0)
        {
            a[1]--;
            a[last]++;
        }
        for(int i=last;i>0;i--)
        {
            if(a[i]>0) ok=0;
            a[i-1]+=a[i];
        }
        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}