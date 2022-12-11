#include <stdio.h>
#include <vector>
#define MX_N 100010
#define A first
#define B second
#define mp make_pair

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vpii;
vpii arr[MX_N];
int pass[MX_N];
int use[MX_N];
int n;

void dfs(int node,int x) {
	int i;
	pass[node] = 1;
	for(i=0;i<arr[node].size();i++) {
		if(pass[arr[node][i].A]) continue;
		if(arr[node][i].B == 2) {
			use[x] = 0;
			use[arr[node][i].A] = 1;
			dfs(arr[node][i].A,arr[node][i].A);
		}else {
			dfs(arr[node][i].A,x);
		}
	}
}
int main() {
	int i;
	scanf("%d",&n);
	for(i=0;i<n-1;i++) {
		int a,b,t;
		scanf("%d %d %d",&a,&b,&t);
		arr[a].push_back(mp(b,t));
		arr[b].push_back(mp(a,t));
	}
	dfs(1,1);
	int ans = 0;
	for(i=1;i<=n;i++) {
		if(use[i])
			ans++;
	}
	printf("%d\n",ans);
	for(i=1;i<=n;i++) {
		if(use[i])
			printf("%d ",i);
	}
	printf("\n");
	return 0;
}