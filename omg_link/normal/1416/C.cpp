#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 300000
typedef long long LL;

int n,a[MN+5];

LL vt[30][2];

void solve(int v[],int w,int n){
	if(n<=1) return;
	if(w<0) return;
	static int tmp[30][2][MN+5];
	int *v0 = tmp[w][0];
	int *v1 = tmp[w][1];
	int n0 = 0;
	int n1 = 0;
	for(int i=0;i<n;i++){
		if(v[i]&(1<<w)){
			v1[n1++] = v[i];
			vt[w][1] += n0;
		}else{
			v0[n0++] = v[i];
			vt[w][0] += n1;
		}
	}
	solve(v0,w-1,n0);
	solve(v1,w-1,n1);
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	solve(a,29,n);
	LL ans = 0;
	int num = 0;
	for(int i=29;i>=0;i--){
		if(vt[i][1]<vt[i][0]){
			num |= (1<<i);
			ans += vt[i][1];
		}else{
			ans += vt[i][0];
		}
	}
	printf("%lld %d\n",ans,num);
}