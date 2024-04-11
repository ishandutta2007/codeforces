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

const int N=500007;

multiset<int>SR[N];
multiset<int>SL[N];
int mnL[N];
int mxL[N];
int mnR[N];
int mxR[N];
int sufL[N];
int sufR[N];
char ans[N];

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
        vector<vector<int>>a(n+2);
        for(int i=1;i<=n;i++)
        {
            a[i]=vector<int>(m+2);
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                SR[i].insert(a[i][j]);
            }
        }
        bool is=0;
        for(int j=1;j<m;j++)
        {
            for(int i=1;i<=n;i++)
            {
                SR[i].erase(SR[i].find(a[i][j]));
                SL[i].insert(a[i][j]);
            }
            vector<pair<int,int>>VL;
            for(int i=1;i<=n;i++)
            {
                mnL[i]=*SL[i].begin();
                mxL[i]=*--SL[i].end();
                mnR[i]=*SR[i].begin();
                mxR[i]=*--SR[i].end();
                VL.pb({mxL[i],i});
            }
            sort(all(VL));
            sufL[n-1]=mnL[VL[n-1].nd];
            sufR[n-1]=mxR[VL[n-1].nd];
            for(int i=n-2;i>=0;i--)
            {
                sufL[i]=min(sufL[i+1],mnL[VL[i].nd]);
                sufR[i]=max(sufR[i+1],mxR[VL[i].nd]);
            }
            for(int i=1;i<=n;i++) ans[i]='R';
            int L=0,R=inf;
            for(int i=0;i<n-1;i++)
            {
                ans[VL[i].nd]='B';
                L=max(L,mxL[VL[i].nd]);
                R=min(R,mnR[VL[i].nd]);
                if(L<sufL[i+1]&&R>sufR[i+1])
                {
                    cout<<"YES"<<endl;
                    for(int l=1;l<=n;l++) cout<<ans[l];
                    cout<<" "<<j<<endl;
                    is=1;
                    break;
                }
            }
            if(is) break;
        }
        if(!is) cout<<"NO"<<endl;
        for(int i=1;i<=n;i++)
        {
            SL[i].clear();
            SR[i].clear();
        }
    }

    return 0;
}