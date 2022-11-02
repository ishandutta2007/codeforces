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
        int n,m;
        cin>>n>>m;
        vector<vector<char>>c(n+1);
        c[0]=vector<char>(m+1,'.');
        set<int>S;
        S.insert(inf);
        for(int i=1;i<=n;i++)
        {
            c[i]=vector<char>(m+1);
            c[i][0]='.';
            for(int j=1;j<=m;j++)
            {
                cin>>c[i][j];
                if(c[i-1][j]=='X'&&c[i][j-1]=='X')  S.insert(j);
            }
        }
        int q,l,r;
        cin>>q;
        while(q--)
        {
            cin>>l>>r;
            if(*S.lower_bound(l+1)<=r) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }

    return 0;
}