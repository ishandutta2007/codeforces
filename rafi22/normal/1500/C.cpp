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

const int N=1507;

int a[N][N];
int b[N][N];
int ord[N];
bool x[N][N];
int cnt[N];
bool is[N];
int pos[N];

void gg()
{
    cout<<-1;
    exit(0);
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
        int n,m;
        cin>>n>>m;
        vector<pair<vector<int>,int>>A,B;
        for(int i=1;i<=n;i++)
        {
            vector<int>V(m);
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                V[j-1]=a[i][j];
            }
            A.pb({V,i});
        }
        for(int i=1;i<=n;i++)
        {
            vector<int>V(m);
            for(int j=1;j<=m;j++)
            {
                cin>>b[i][j];
                V[j-1]=b[i][j];
            }
            B.pb({V,i});
        }
        sort(all(A));
        sort(all(B));
        for(int i=0;i<n;i++)
        {
            if(A[i].st!=B[i].st) gg();
            ord[B[i].nd]=A[i].nd;
        }
        for(int j=1;j<=m;j++)
        {
            for(int i=1;i<n;i++)
            {
                if(a[ord[i]][j]>a[ord[i+1]][j])
                {
                    x[i][j]=1;
                    cnt[j]++;
                }
            }
        }
        deque<int>Q;
        for(int j=1;j<=m;j++) if(cnt[j]==0) Q.pb(j);
        vector<int>ans;
        while(sz(Q)>0)
        {
            int j=Q[0];
            Q.pop_front();
            ans.pb(j);
            for(int i=1;i<n;i++)
            {
                if(a[ord[i]][j]!=a[ord[i+1]][j]&&!is[i])
                {
                    is[i]=1;
                    for(int j=1;j<=m;j++)
                    {
                        if(x[i][j])
                        {
                            x[i][j]=0;
                            cnt[j]--;
                            if(cnt[j]==0) Q.pb(j);
                        }
                    }
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(!is[i]&&ord[i]>ord[i+1]) gg();
        }
        reverse(all(ans));
        cout<<sz(ans)<<endl;
        for(auto x:ans) cout<<x<<" ";
    }

    return 0;
}