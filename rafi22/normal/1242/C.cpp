#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

const int K=16,N=5007;

int a[K][N];
pair<int,int> G[K][N];
bool odw[K][N];
map<int,pair<int,int>>xd;
int d[K];
int n[K];
deque<pair<int,int>>cycle[K*N];
int msk[1<<K];
int m[K*N];
bool DP[1<<K];
int zkad[1<<K];

pair<int,int>co;
int it=0;

void dfs(int i,int j)
{
    odw[i][j]=1;
    cycle[it].pb({i,j});
    if(G[i][j].nd==0) return ;
    if(odw[G[i][j].st][G[i][j].nd]) co=G[i][j];
    else dfs(G[i][j].st,G[i][j].nd);
}

int a1[K],a2[K];

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
        int k,sum=0;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            cin>>n[i];
            for(int j=1;j<=n[i];j++)
            {
                cin>>a[i][j];
                xd[a[i][j]]={i,j};
                d[i]+=a[i][j];
            }
            sum+=d[i];
        }
        if(sum%k!=0)
        {
            cout<<"No";
            return 0;
        }
        sum/=k;
        for(int i=0;i<k;i++) d[i]-=sum;
        for(int i=0;i<k;i++)
        {
            for(int j=1;j<=n[i];j++)
            {
                G[i][j]=xd[a[i][j]-d[i]];
                if(G[i][j].st==i&&G[i][j].nd!=j) G[i][j]={0,0};
            }
        }
        for(int i=0;i<k;i++)
        {
            for(int j=1;j<=n[i];j++)
            {
                if(odw[i][j]) continue;
                it++;
                co={0,0};
                dfs(i,j);
                while(sz(cycle[it])>0&&cycle[it][0]!=co) cycle[it].pop_front();
                bool zle=0;
                for(auto x:cycle[it])
                {
                    if((m[it]&(1<<x.st))) zle=1;
                    m[it]|=1<<x.st;
                }
                if(!zle) msk[m[it]]=it;
            }
        }
        DP[0]=1;
        for(int i=1;i<1<<k;i++)
        {
            for (int s=i;; s=(s-1)&i)
            {
                if(DP[s]&&msk[i^s]>0)
                {
                    DP[i]=1;
                    zkad[i]=msk[i^s];
                    break;
                }
                if(s==0) break;
            }
        }
        int x=(1<<k)-1;
        if(!DP[x])
        {
            cout<<"No";
            return 0;
        }
        while(x>0)
        {
            for(auto z:cycle[zkad[x]])
            {
                a1[z.st]=a[z.st][z.nd];
                a2[G[z.st][z.nd].st]=z.st+1;
            }
            x^=m[zkad[x]];
        }
        cout<<"Yes"<<endl;
        for(int i=0;i<k;i++) cout<<a1[i]<<" "<<a2[i]<<endl;
    }

    return 0;
}