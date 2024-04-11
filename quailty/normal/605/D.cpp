#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
struct card
{
    int a,b,c,d;
    card(){}
    card(int _a,int _b,int _c,int _d):a(_a),b(_b),c(_c),d(_d){}
}s[MAXN];
set<pair<int,int> >st[MAXN<<1];
int dis[MAXN],pre[MAXN];
void bfs(int n)
{
    memset(dis,INF,sizeof(dis));
    memset(pre,-1,sizeof(pre));
    queue<int>q;
    q.push(0);
    dis[0]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=s[u].c;i>0;i-=i&(-i))
            for(set<pair<int,int> >::iterator itr=st[i].begin();itr!=st[i].end();)
            {
                if(itr->first <=s[u].d)
                {
                    int v=itr->second;
                    if(dis[v]==INF)
                    {
                        q.push(v);
                        dis[v]=dis[u]+1;
                        pre[v]=u;
                    }
                    st[i].erase(itr++);
                }
                else break;
            }
    }
}
int xx[MAXN<<1],tot;
int main()
{
    int n;
    scanf("%d",&n);
    s[0]=card(0,0,0,0);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d%d",&s[i].a,&s[i].b,&s[i].c,&s[i].d);
    for(int i=0;i<=n;i++)
        xx[tot++]=s[i].a;
    for(int i=0;i<=n;i++)
        xx[tot++]=s[i].c;
    sort(xx,xx+tot);
    for(int i=0;i<=n;i++)
        s[i].a=lower_bound(xx,xx+tot,s[i].a)-xx+1;
    for(int i=0;i<=n;i++)
        s[i].c=lower_bound(xx,xx+tot,s[i].c)-xx+1;
    for(int i=1;i<=n;i++)
        for(int j=s[i].a;j<=tot;j+=j&(-j))
            st[j].insert(make_pair(s[i].b,i));
    bfs(n);
    if(dis[n]<INF)
    {
        printf("%d\n",dis[n]);
        stack<int>st;
        for(int i=n;i!=-1;i=pre[i])
            st.push(i);
        bool flag=0;
        while(!st.empty())
        {
            if(st.top()>0)
            {
                if(flag)printf(" ");
                else flag=1;
                printf("%d",st.top());
            }
            st.pop();
        }
    }
    else printf("-1\n");
    return 0;
}