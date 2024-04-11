#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
int ne[30000],S,T,d[30000],q[30000],cnt;
int e[205],o[205],a[205],vis[205],qd;
deque<int>g[205];
struct node{
	int v,next,w;
}edge[30000];
bool ss(int x){
	if(x<2)return 0;
    for(int i=2;i<=sqrt(x);i++)if(x%i==0)return 0;
    return 1;
}
void add(int u, int v, int w){
    edge[cnt].v=v;
    edge[cnt].next=ne[u];
    edge[cnt].w=w;
    ne[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].next=ne[v];
    edge[cnt].w=0;
    ne[v]=cnt++;
}
bool bfs(){
    memset(d,-1,sizeof(d));
    d[S]=0;
    int r=0;
    q[r++]=S;
    for(int l=0;l<r;l++){
        int u=q[l];
        for(int i=ne[u];i!=-1;i=edge[i].next){
            if(edge[i].w>0 && d[edge[i].v]==-1){
                d[edge[i].v] = d[u]+1;
                q[r++]=edge[i].v;
            }
        }
    }
    return d[T]!=-1;
}
int dfs(int u,int flow){
    if(u==T)return flow;
    int re=0,t;
    for(int i=ne[u];i!=-1;i=edge[i].next){
        if(d[edge[i].v]==d[u]+1&&edge[i].w>0){
			t=dfs(edge[i].v,min(edge[i].w,flow));
			if(!t)continue;
            edge[i].w-=t;
            edge[i^1].w+=t;
            flow-=t;
            re+=t;
            if(!flow)break;
        }
    }
    if(re)return re;
    d[u]=-1;
    return 0;
}
void dfs2(int u,int co,int flag){
    vis[u]=1;
    if(flag)g[co].push_front(u);else g[co].push_back(u);
    for(int i=ne[u];i!=-1;i=edge[i].next){
        if(edge[i].v==S||edge[i].v==T)continue;
        if((i&1)&&edge[i].w==1&&!vis[edge[i].v])dfs2(edge[i].v,co,flag);
        if(!(i&1)&&edge[i].w==0&&!vis[edge[i].v])dfs2(edge[i].v,co,abs(flag-(u==qd)));
    }
}
int main(){
    memset(ne,-1,sizeof(ne));
    int n,sum=0,q=0;
    cin>>n;
    S=0,T=n+1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]&1){
        	o[++o[0]]=i;
			add(S,i,2);
		}else{
			e[++e[0]]=i;
			add(i,T,2);
		}
    }
    if(o[0]!=e[0]){
		cout<<"Impossible";
    	return 0;
	} 
    for(int i=1;i<=o[0];i++){
    	for(int j=1;j<=e[0];j++){
    		if(ss(a[o[i]]+a[e[j]])){
    			add(o[i],e[j],1);
			}
		}
	}
    while(bfs()){
    	sum+=dfs(S,2147483647);
	}
    if(sum!=n){
    	cout<<"Impossible";
    	return 0;
	}
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        qd=i;
        dfs2(i,++q,1);
    }
    cout<<q<<'\n';
    for(int i=1;i<=q;i++){
        cout<<g[i].size()<<' ';
        while(!g[i].empty()){
        	cout<<g[i].front()<<' ';
        	g[i].pop_front();
		}
		cout<<'\n';
    }
    return 0;
}