#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
int du[100005],q[100005],vis[100005];
vector<int> adj[100005];

bool check(vector<int> &vec){
	assert(vec.size()==k);
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec.size();j++){
			if(i==j) continue;
			auto it=lower_bound(adj[vec[i]].begin(),adj[vec[i]].end(),vec[j]);
			if(it==adj[vec[i]].end()||*it!=vec[j]) return false;
		}
	}
	printf("2\n");
	for(auto r:vec) printf("%d ",r);
	printf("\n");
	return true;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint(); k=readint();
		for(int i=1;i<=n;i++) vis[i]=du[i]=0,adj[i].clear();
		int x,y;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint();
			adj[x].pb(y),adj[y].pb(x);
			du[x]++,du[y]++;
		}
		for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end());
		int front=0,rear=0;
		for(int i=1;i<=n;i++) if(du[i]<k) q[rear++]=i,vis[i]=1;
		bool fl=0;
		while(front<rear){
			int t=q[front++];
			vis[t]=2;
			if(du[t]<k-1){
				for(auto v:adj[t]) if((--du[v])<k&&!vis[v]) q[rear++]=v,vis[v]=1;
			}
			else if(du[t]==k-1){
				vector<int> vec(0); vec.pb(t);
				for(auto v:adj[t]) if(vis[v]<=1&&du[v]>=k-1) vec.pb(v);
				if(vec.size()==k&&check(vec)){
					fl=1;
					break;
				}
				for(auto v:adj[t]) if((--du[v])<k&&!vis[v]) q[rear++]=v,vis[v]=1;
			}
		}
		vector<int> vec(0);
		for(int i=1;i<=n;i++) if(!vis[i]) vec.pb(i);
		if(!fl&&vec.size()){
			printf("1 %d\n",vec.size());
			for(auto r:vec) printf("%d ",r);
			printf("\n");
		}
		else if(!fl) printf("-1\n");
	}
	return 0;
}