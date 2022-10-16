#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;
const int N=200005;
vector<int> graf[N],drvo[N];
int low[N],pre[N],timee=1,cnt2,up[N][20],d[N],visited[N];
stack<int> stk;
void trajan(int tr)
{
    low[tr]=pre[tr]=timee++;
    stk.push(tr);
    for(int i=0;i<graf[tr].size();i++)
    {
        int sl=graf[tr][i];
        if(pre[sl]==0)
        {
            trajan(sl);
            low[tr]=min(low[tr],low[sl]);
            if(low[sl]>=pre[tr])
            {
                //printf("Komponenta: %i\n",cnt2);
                while(stk.top()!=sl)
                {
                    //printf("%i ",stk.top());
                    drvo[stk.top()].pb(cnt2);
                    drvo[cnt2].pb(stk.top());
                    stk.pop();
                }
                //printf("%i %i\n",sl,tr);
                stk.pop();
                drvo[sl].pb(cnt2);
                drvo[cnt2].pb(sl);
                drvo[tr].pb(cnt2);
                drvo[cnt2].pb(tr);
                cnt2++;
            }
        }
        else
        {
            low[tr]=min(low[tr],pre[sl]);
        }
    }
}
int lca(int a,int b)
{
    if(d[a]<d[b])
        swap(a,b);
    for(int i=19;i>=0;i--)
    {
        if(d[a]-(1<<i)>=d[b])
        {
            a=up[a][i];
        }
    }
    if(a==b)
        return a;
    for(int i=19;i>=0;i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];
        }
    }
    return up[a][0];
}
int main()
{
    int n,m,qu;
    scanf("%i %i %i",&n,&m,&qu);
    cnt2=n+1;
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        graf[a].pb(b);
        graf[b].pb(a);
    }
    trajan(1);
    queue<int> q;
    q.push(1);
    d[1]=0;
    visited[1]=1;
    up[1][0]=-1;
    while(!q.empty())
    {
        int tr=q.front();
        q.pop();
        for(int i=0;i<drvo[tr].size();i++)
        {
            int sl=drvo[tr][i];
            if(visited[sl]==0)
            {
                visited[sl]=1;
                q.push(sl);
                d[sl]=d[tr]+1;
                up[sl][0]=tr;
            }
        }
    }
    for(int j=1;j<20;j++)
    {
        for(int i=1;i<N;i++)
        {
            int mid=up[i][j-1];
            if(mid==-1)
                up[i][j]=-1;
            else
                up[i][j]=up[mid][j-1];
        }
    }
    while(qu--)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        printf("%i\n",(d[a]+d[b]-2*d[lca(a,b)])/2);
    }
    return 0;
}