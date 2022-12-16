#include <stdio.h>
#include <set>
#include <vector>
#define MN 1000

int n,id,a[MN+5][MN+5],b[MN+5];
typedef struct{
	int u,v;
}edge;
std::vector<edge> e;

int solve(std::set<int>& v){
	if(v.size()==1){
		int x = *v.begin();
		v.clear();
		b[x] = a[x][x];
		return x;
	}
	int mx = 0;
	int fir = *v.begin();
	for(auto x:v)
		mx = std::max(mx,a[x][fir]);
	int r = n+(++id);
	b[r] = mx;
	std::set<int> nv;
	while(!v.empty()){
		int x = *v.begin();
		for(auto p:v)
			if(a[x][p]!=mx)
				nv.insert(p);
		for(auto p:nv)
			v.erase(p);
		int p = solve(nv);
		e.push_back((edge){p,r});
	}
	return r;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	std::set<int> v;
	for(int i=1;i<=n;i++)
		v.insert(i);
	int r = solve(v);
	printf("%d\n",n+id);
	for(int i=1;i<=n+id;i++)
		printf("%d ",b[i]);
	puts("");
	printf("%d\n",r);
	for(auto p:e){
		printf("%d %d\n",p.u,p.v);
	}
}