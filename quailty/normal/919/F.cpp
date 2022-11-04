#include<bits/stdc++.h>
using namespace std;

map<vector<int>,int> mp;
vector<int> sta[505];

inline int getid(vector<int> &st)
{
    if(!mp[st])
    {
        mp[st]=(int)mp.size();
        sta[(int)mp.size()]=st;
    }
    return mp[st];
}

void dfs(int dep,int la,vector<int> tmp)
{
    if(dep==8)
    {
        getid(tmp);
        return;
    }
    for(int i=la;i<5;i++)
    {
        tmp.push_back(i);
        dfs(dep+1,i,tmp);
        tmp.pop_back();
    }
}

vector<int> pre[505][505];
int dp[2][505][505],out[2][505][505];

void build()
{
    dfs(0,0,vector<int>());
    int n=(int)mp.size();
    vector<int> a,b,c(8);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            a=sta[i],b=sta[j];
            for(int p=0;p<8;p++)
                for(int q=0;q<8;q++)
                {
                    if(a[p]*b[q]==0)continue;
                    for(int r=0;r<8;r++)
                        c[r]=a[r];
                    c[p]=(a[p]+b[q])%5;
                    sort(c.begin(),c.end());
                    int k=getid(c);
                    out[0][i][j]++;
                    out[1][j][i]++;
                    pre[k][j].push_back(i);
                }
        }
    struct node
    {
        int f,x,y;
    };
    queue<node> q;
    for(int i=1;i<=n;i++)
    {
        q.push({0,i,1});
        dp[0][i][1]=-1;
        q.push({1,1,i});
        dp[1][1][i]=-1;
    }
    vector<node> ask;
    while(!q.empty())
    {
        node tmp=q.front();
        q.pop();
        int uf=tmp.f,ux=tmp.x,uy=tmp.y;
        ask.clear();
        int vf=uf^1;
        if(!vf)for(int i=0;i<(int)pre[ux][uy].size();i++)
        {
            int vx=pre[ux][uy][i],vy=uy;
            ask.push_back({vf,vx,vy});
        }
        else for(int i=0;i<(int)pre[uy][ux].size();i++)
        {
            int vx=ux,vy=pre[uy][ux][i];
            ask.push_back({vf,vx,vy});
        }
        for(int i=0;i<(int)ask.size();i++)
        {
            int vx=ask[i].x,vy=ask[i].y;
            if(dp[uf][ux][uy]==-1)
            {
                if(!dp[vf][vx][vy])
                {
                    dp[vf][vx][vy]=1;
                    q.push({vf,vx,vy});
                }
            }
            else
            {
                if((--out[vf][vx][vy])==0 && !dp[vf][vx][vy])
                {
                    dp[vf][vx][vy]=-1;
                    q.push({vf,vx,vy});
                }
            }
        }
    }
}

int main()
{
    build();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int f;
        vector<int> a(8),b(8);
        scanf("%d",&f);
        for(int i=0;i<8;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<8;i++)
            scanf("%d",&b[i]);
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int go=(f ? -1 : 1)*dp[f][getid(a)][getid(b)];
        if(go==1)printf("Alice\n");
        else if(go==-1)printf("Bob\n");
        else printf("Deal\n");
    }
    return 0;
}