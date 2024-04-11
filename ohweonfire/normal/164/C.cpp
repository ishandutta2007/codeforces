#include<bits/stdc++.h>
using namespace std;
const int N=2005,M=4005;
const int inf=1<<29;
int head[N],nc;
struct Edge
{
    int x,y,next;
    int cap,cost;
} edge[M*3];
void addedge(int x,int y,int cap,int cost)
{
    edge[nc].x=x;
    edge[nc].y=y;
    edge[nc].cap=cap;
    edge[nc].next=head[x];
    edge[nc].cost=cost;
    head[x]=nc++;
    edge[nc].x=y;
    edge[nc].y=x;
    edge[nc].cap=0;
    edge[nc].next=head[y];
    edge[nc].cost=-cost;
    head[y]=nc++;
}
int dist[N],pe[N],pv[N];
bool mark[N];
int mincost(int n)
{
    int S=0,T=n-1,flow=0,cost=0,mxf,i,j,k;
    while(1)
    {
        for(i=0;i<n;i++)
            dist[i]=inf;
        memset(mark,false,sizeof(mark));
        queue<int> Q;
        Q.push(S);
        mark[S]=true;
        dist[S]=0;
        while(!Q.empty())
        {
            int now=Q.front();
            Q.pop();
            mark[now]=false;
            for(i=head[now];i!=-1;i=edge[i].next)
            {
                Edge x=edge[i];
                if(x.cap&&dist[x.y]>x.cost+dist[now])
                {
                    dist[x.y]=x.cost+dist[now];
                    pe[x.y]=i;
                    pv[x.y]=now;
                    if(!mark[x.y])
                    {
                        mark[x.y]=true;
                        Q.push(x.y);
                    }
                }
            }
        }
        if(dist[T]==inf)
            return cost;
        for(k=T,mxf=inf;k!=S;k=pv[k])
            mxf=min(mxf,edge[pe[k]].cap);
        flow+=mxf;cost+=dist[T]*mxf;
        for(k=T;k!=S;k=pv[k])
            edge[pe[k]].cap-=mxf,edge[pe[k]^1].cap+=mxf;
    }
}
set<pair<int,int> > used;
int data[N][3],ar[N];
int num,Id[N];
map<int,int>hashing;
int main()
{
    int T;
    for(T=1;T;T--)
    {
        int i,j,k,n=1;
        hashing.clear();
        memset(head,-1,sizeof(head));
        nc=0;
        scanf("%d%d",&num,&k);
        for(i=0;i<num;i++)
        {
            scanf("%d%d%d",&data[i][0],&data[i][1],&data[i][2]);
            data[i][1]+=data[i][0];
			ar[n++]=data[i][0];
			ar[n++]=data[i][1];
		}
        sort(ar+1,ar+n);
        for(i=2,j=1;i<n;i++)
            if(ar[j]!=ar[i])
                ar[++j]=ar[i];
        n=j+1;
        addedge(0,1,k,0);
        for(i=1;i<n;i++)
        {
            hashing[ar[i]]=i;
            addedge(i,i+1,k,0);
        }
        for(i=0;i<num;i++)
        {
        	Id[i]=nc;
            addedge(hashing[data[i][0]],hashing[data[i][1]],1,-data[i][2]);
        }
        mincost(n);
        for(int i=0;i<num;i++)
        {
        	if(edge[Id[i]].cap==0)
        		putchar('1');
        	else
        		putchar('0');
        	putchar(' ');
        }
    }
    return 0;
}