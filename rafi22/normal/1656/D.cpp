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
        int n,K=0;
        cin>>n;
        bool nie=0;
        for(int i=1;i<=31;i++)
        {
            int k=(1LL<<i);
            if(k*(k-1)/2>=n) break;
            if((n-(k*(k-1)/2))%k==0) K=k;
        }
        if(K>0) cout<<K<<endl;
        else
        {
            while(n%2==0) n/=2;
            if(n>1) cout<<n<<endl;
            else cout<<-1<<endl;
        }
    }

    return 0;
}