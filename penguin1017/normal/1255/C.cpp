#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define pb push_back
using namespace std;
const int N=1e5+9;
int a[N][3],vis[N],ans[N],deg[N];
queue<int> q;
vector<int> g[N];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n-2){
		rep(j,0,3)scanf("%d",&a[i][j]),++deg[a[i][j]],g[a[i][j]].pb(i);
	}
	int flag=0;
	rep(i,1,n+1){
		if(deg[i]==1){
			if(!flag)q.push(i),flag=1;
			else{
				ans[n-1]=i,deg[i]=0;
				for(auto v:g[i]){
					rep(i,0,3){
						int num=a[v][i];
						if(deg[num]==2){
							deg[num]=0;
							ans[n-2]=num;
						}
					}
				}
			} 
		}
	}
	int cnt=0;
	while(!q.empty()){
		int u=q.front();
		q.pop(); 
		ans[cnt++]=u;
		for(auto v:g[u]){
			if(!vis[v]){
				vis[v]=1;
				rep(i,0,3){
					int num=a[v][i];
					deg[num]--;
					if(deg[num]==1)q.push(num);
				}
			}
		}
	}
	rep(i,0,n)printf("%d ",ans[i]);
}