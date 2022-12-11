#include <stdio.h>
#include <algorithm>
#include <queue>
#define mp make_pair
#define A first
#define B second

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> piii;
priority_queue<pii> que;
piii arr[600010];
pii tmp[600010];
int ans[300010];
int out[600010];
int n,m;

int cmp(piii a,piii b) {
	int p = abs(a.A.A);
	int k = abs(b.A.A);
	if(p != k)
		return p < k;
	return a < b;
}
int main() {
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++) {
		scanf("%d %d %d",&arr[2*i].A.A,&arr[2*i+1].A.A,&arr[2*i].B);
		arr[2*i+1].B = arr[2*i].B;
		arr[2*i+1].A.A = -arr[2*i+1].A.A-1;
		arr[2*i].A.B = arr[2*i+1].A.B = i;
	}
	sort(arr,arr+2*m,cmp);
	for(i=1,j=0;i<=n;i++) {
		while(j < 2*m && abs(arr[j].A.A) == i) {
			if(arr[j].A.A < 0) {
				out[arr[j].A.B] = 1;
			}else {
				que.push(mp(-arr[j].A.B,arr[j].B));
			}
			j++;
		}
		pii top;
		int l = 0;
		while(!que.empty()) {
			top = que.top();
			if(top.B == i) {
				tmp[l++] = top;
			}else if(!out[-top.A])
				break;
			que.pop();
		}
		if(que.empty())
			ans[i] = 0;
		else
			ans[i] = top.B;
		while(l--)
			que.push(tmp[l]);
	}
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}