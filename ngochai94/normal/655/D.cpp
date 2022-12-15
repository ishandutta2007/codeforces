#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int n,m,fin[100005],cnt[100005],cur,err,u,v,after[100005];
vector<int> beat[100005];
pair<int,int> record[100005];

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    For(i,0,m)
    {
        cin>>u>>v;
        u--;v--;
        record[i]={u,v};
        beat[u].pb(v);
        cnt[v]++;
    }
    err=0;
    For(i,0,n) if(!cnt[i])
    {
        cur=i;
        err++;
    }
    if(err!=1)
    {
        cout<<-1;return 0;
    }
    For(i,1,n)
    {
        int tmp=cur;
        err=0;
        for(auto nex:beat[tmp])
        {
            cnt[nex]--;
            if(!cnt[nex])
            {
                err++;
                cur=nex;
            }
        }
        if(err!=1)
        {
            cout<<-1;return 0;
        }
        after[tmp]=cur;
    }
    int ans=n-1;
    reset(cnt,-1);
    For(i,0,m)
    {
        u=record[i].first;
        v=record[i].second;
        if(v==after[u])
        {
            cnt[v]++;
            if(!cnt[v]) ans--;
        }
        if(!ans)
        {
            cout<<i+1;
            return 0;
        }
    }
    cout<<-1;
}