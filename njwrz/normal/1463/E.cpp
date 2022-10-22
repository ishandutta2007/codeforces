#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int n,k,p[300005],nxt[300005],it[300005],in[300005],ans[300005];
int d[300005],st[300005];
V<int> v[300005],g[300005],num[300005];
bool start[300005];
P<int,int> h[300005];
void dfs(int x,int lst){
    for(auto u:v[x]){
       	d[u]=d[x]+1;
        if(it[u]!=lst){
            g[lst].PB(it[u]);
            dfs(u,it[u]);in[it[u]]++;
        }else {
        	if(st[u]<st[x]){
        		puts("0");exit(0);
			}
        	dfs(u,lst);
		}
    }
}
signed main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n)scanf("%d",&p[i]),v[p[i]].PB(i);
    int x,y;
    bool f=1;
    FOR(i,1,k){
        scanf("%d%d",&x,&y);h[i]=MP(x,y);
        if(nxt[x])f=0;
        nxt[x]=y;start[y]=1;
    }
    if(!f){
        putchar('0');RE 0;
    }
    int cnt=0;
    FOR(i,1,n){
        if(!it[i]&&!start[i]){
            cnt++;
            int t=i;
            int stc=0;
            while(t){
            	st[t]=++stc;
            	if(it[t]){
            		puts("0");RE 0;
				}
                it[t]=cnt;num[cnt].PB(t);
                t=nxt[t];
            }
        }
    }
    dfs(0,0);
    queue<int> q;
    q.emplace(0);
    cnt=0;
    while(!q.empty()){
        int cur=q.front();q.pop();
        for(auto u:num[cur]){
            ans[++cnt]=u;
        }
        for(auto u:g[cur]){
            in[u]--;
            if(!in[u]){
                q.emplace(u);
            }
        }
    }
//    FOR(i,1,k){
//    	cout<<d[h[i].S]<<' '<<d[h[i].F]<<'\n';
//    	if(d[h[i].S]<d[h[i].F]){
//    		f=0;break;
//		}
//	}
    if(cnt!=n||!f){
        puts("0");
    }else {
        FOR(i,1,n)printf("%d ",ans[i]);
    }
    RE 0;
}