#include <bits/stdc++.h>

//#define int long long
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

const bool multi=0;

vector<int> v;
int ile[100007];
int tab[100007];
int pref[650][100007];

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
		int n,m,l,r;
		cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>tab[i];
        for(int i=1;i<=n;i++)
        {
            if(tab[i]<=n) ile[tab[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(ile[i]>=i)
            {
                v.pb(i);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v.size();j++)
            {
                pref[j][i]=pref[j][i-1];
                if(tab[i]==v[j]) pref[j][i]++;
            }
        }
        for(int i=0;i<m;i++)
        {
            cin>>l>>r;
            int ans=0;
            for(int j=0;j<v.size();j++)
            {
                if(pref[j][r]-pref[j][l-1]==v[j]) ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}