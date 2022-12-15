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

int u,v,n,m,vst[100005],cnt;
map<pair<int,int>,int > edge;
vector<int> ans[2],tmp1,tmp2;
vector<int> same[100005],dif[100005];
char c;
queue<int> q;

int f()
{
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int nex:same[u])
        {
            if(!vst[nex])
            {
                vst[nex]=vst[u];
                if(vst[nex]==1) tmp1.pb(nex);
                else tmp2.pb(nex);
                q.push(nex);
            }
            else if(vst[nex]!=vst[u]) return -1;
        }
        for(int nex:dif[u])
        {
            if(!vst[nex])
            {
                vst[nex]=-vst[u];
                if(vst[nex]==1) tmp1.pb(nex);
                else tmp2.pb(nex);
                q.push(nex);
            }
            else if(vst[nex]==vst[u]) return -1;
        }
    }
    //cout<<col<<' '<<ans[col].size()<<endl;
    //for(auto i:ans[col]) cout<<i<<' '; cout<<endl;
    return 0;
}

void bfs(int col)
{
    reset(vst,0);
    while(!q.empty()) q.pop();
    For(i,1,1+n) if(!vst[i])
    {
        //cout<<i<<endl;
        tmp1.clear();
        tmp2.clear();
        vst[i]=1;
        tmp1.pb(i);
        while(!q.empty()) q.pop();
        q.push(i);
        int sig = f();
        if(sig==-1)
        {
            ans[col].clear();
            //cout<<"here"<<endl;
            return;
        }
        if(tmp1.size()<tmp2.size())
        {
            for(auto i:tmp1) ans[col].pb(i);
        }
        else for(auto i:tmp2) ans[col].pb(i);
    }
}


int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    int cb=0,cr=0;
    For(i,1,1+m)
    {
        cin>>u>>v>>c;
        if(u>v) swap(u,v);
        int col = c=='R'?1:0;
        edge[{u,v}] = col;
        if(col)
        {
            cr++;
            same[u].pb(v);
            same[v].pb(u);
        }
        else
        {
            cb++;
            dif[u].pb(v);
            dif[v].pb(u);
        }
    }
    if(!cb||!cr)
    {
        cout<<0<<endl;return 0;
    }
    bfs(1);
    For(i,1,1+n)
    {
        dif[i].clear();
        same[i].clear();
    }
    for(auto p:edge)
    {
        u=p.first.first;
        v=p.first.second;
        if(!p.second)
        {
            same[u].pb(v);
            same[v].pb(u);
        }
        else
        {
            dif[u].pb(v);
            dif[v].pb(u);
        }
    }
    bfs(0);
    if(ans[0].size()==0)
    {
        if(ans[1].size()==0) cout<<-1;
        else
        {
            cout<<ans[1].size()<<endl;
            for(auto i:ans[1]) cout<<i<<' ';
        }
    }
    else
    {
        if(ans[1].size()==0||ans[1].size()>ans[0].size())
        {
            cout<<ans[0].size()<<endl;
            for(auto i:ans[0]) cout<<i<<' ';
        }
        else
        {
            cout<<ans[1].size()<<endl;
            for(auto i:ans[1]) cout<<i<<' ';
        }
    }
}