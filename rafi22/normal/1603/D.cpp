#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;


const int N=100003,L=20,S=330;

int phi[N];
int p[N];
bool is[N];
int DP[N][L];
int p1[N][S];
int p2[N][S];
deque<pair<int,int>>Q[L];

int c(int l,int r)
{
    if(l>r) return inf;
    int ans=0;
    if(l<=320) ans+=p2[r][l];
    int k=min(r/l,320LL);
    ans+=p1[r][k]-max(0LL,l-r/(k+1)-1)*p[k];
    return ans;
}
int f(int i,int j,int k)
{
    return DP[k][j-1]+c(k+1,i);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt=0;
    for(int i=1;i<N;i++) phi[i]=1;
    for(int i=2;i<N;i++)
    {
        if(is[i]) continue;
        for(int j=i;j<N;j+=i)
        {
            int x=j,y=1;
            while(x%i==0)
            {
                x/=i;
                y*=i;
            }
            phi[j]*=y-y/i;
        }
        for(int j=i;j<N;j+=i) is[j]=1;
    }
    for(int i=1;i<N;i++) p[i]=p[i-1]+phi[i];
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<=320;j++)
        {
            p1[i][j]=p1[i][j-1]+p[j]*(i/j-i/(j+1));
        }
        for(int k=320;k>0;k--)
        {
            int j=i/k;
            if(j<=320) continue;
            p2[i][k]=p2[i][k+1]+p[j];
        }
    }
    for(int i=0;i<N;i++) for(int j=0;j<L;j++) DP[i][j]=inf;
    DP[0][0]=0;
    for(int j=0;j<L;j++) Q[j].pb({0,1});
    for(int i=1;i<N;i++)
    {
        for(int j=L-1;j>0;j--)
        {
            while(sz(Q[j])>1&&Q[j][1].nd<=i) Q[j].pop_front();
            DP[i][j]=f(i,j,Q[j][0].st);
            if(j==L-1) continue;
            while(sz(Q[j+1])>0&&f(Q[j+1].back().nd,j+1,Q[j+1].back().st)>f(Q[j+1].back().nd,j+1,i)) Q[j+1].pop_back();
            if(sz(Q[j+1])==0) Q[j+1].pb({i,i+1});
            else
            {
                int l=max(i+1,Q[j+1].back().nd),r=N-1,sr,k=N;
                while(l<=r)
                {
                    sr=(l+r)/2;
                    if(f(sr,j+1,Q[j+1].back().st)>f(sr,j+1,i))
                    {
                        k=sr;
                        r=sr-1;
                    }
                    else l=sr+1;
                }
                if(k!=N) Q[j+1].pb({i,k});
            }
        }
    }
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        if(k>=20) cout<<n<<endl;
        else cout<<DP[n][k]<<endl;
    }


    return 0;
}