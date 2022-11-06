#include <queue>
#include <cstdio>
using namespace std;
const int Maxn=100000;
const int Maxm=200000;
int n,m;
int w[Maxn+5];
int num[Maxn+5];
struct Node{
	int x,y;
}a[Maxm+5];
bool vis[Maxm+5];
bool un_w[Maxn+5];
int lis[Maxm+5],len;
queue<int> q;
vector<int> id[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		num[a[i].x]++;
		num[a[i].y]++;
		id[a[i].x].push_back(i);
		id[a[i].y].push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(num[i]<=w[i]){
			un_w[i]=1;
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<(int)id[u].size();i++){
			if(vis[id[u][i]]){
				continue;
			}
			lis[++len]=id[u][i];
			vis[id[u][i]]=1;
			num[a[id[u][i]].x]--;
			num[a[id[u][i]].y]--;
			if(!un_w[a[id[u][i]].x]&&num[a[id[u][i]].x]<=w[a[id[u][i]].x]){
				un_w[a[id[u][i]].x]=1;
				q.push(a[id[u][i]].x);
			}
			if(!un_w[a[id[u][i]].y]&&num[a[id[u][i]].y]<=w[a[id[u][i]].y]){
				un_w[a[id[u][i]].y]=1;
				q.push(a[id[u][i]].y);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!un_w[i]){
			puts("DEAD");
			return 0;
		}
	}
	puts("ALIVE");
	for(int i=len;i>0;i--){
		printf("%d ",lis[i]);
	}
	puts("");
	return 0;
}