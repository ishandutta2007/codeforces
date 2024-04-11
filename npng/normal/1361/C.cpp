#include <cstdio>
#include <vector>
using namespace std;
const int Maxn=500000,Maxk=20;
int N;
int a[Maxn+5],b[Maxn+5],deg[1<<Maxk|5];
bool v[1<<Maxk|5],used[Maxn<<1|5];
struct edge{
	int n,id;
};
vector<edge> c[1<<Maxk|5];
int dfs(int n){
	int ctr=deg[n];
	v[n]=1;
	for(auto x:c[n]){
		if(!v[x.n]){
			ctr+=dfs(x.n);
		}
	}
	return ctr;
}
bool test(int bit, bool out=0){
	int all=(1<<bit)-1;
	for(int i=0;i<=all;i++){
		v[i]=deg[i]=0;
		c[i].clear();
	}
	for(int i=0;i<N;i++){
		deg[a[i]&all]++;
		deg[b[i]&all]++;
		c[a[i]&all].push_back({b[i]&all,i<<1|1});
		c[b[i]&all].push_back({a[i]&all,i<<1});
	}
	for(int i=0;i<=all;i++){
		if(deg[i]&1){
			return 0;
		}
	}
	if(dfs(a[0]&all)==N*2){
		return 1;
	}
	return 0;
}
void dfs2(int n,int p=-1){
	for(;!c[n].empty();){
		edge x=c[n].back();
		c[n].pop_back();
		if(used[x.id/2]){
			continue;
		}
		used[x.id/2]=1;
		dfs2(x.n, x.id);
	}
	if(~p){
		printf("%d %d ",p+1,(p^1)+1);
	}
}
int main(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d%d",a+i,b+i);
	}
	if(N==1){
		printf("%d\n1 2\n",a[0]==b[0]?20:__builtin_ctz(a[0]^b[0]));
		return 0;
	}
	int ans=-1;
	for(int i=Maxk;i>=0;i--){
		if(test(i)){
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	dfs2(a[0]&(1<<ans)-1);
	puts("");
	return 0;
}