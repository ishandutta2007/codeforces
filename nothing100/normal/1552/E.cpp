#include<bits/stdc++.h>
using namespace std;
int n,k,c[10010],pre[10010],now[110],bl[10010];
int res[110][2]; 
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n*k;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n*k;i++){
		pre[i]=now[c[i]];
		now[c[i]]=i;
		if (res[c[i]][0]==0&&pre[i]){
			int ma=0;
			for (int j=pre[i];j<=i;j++) ma=max(bl[j],ma);
			if (ma<(n-1)/(k-1)+1){
				res[c[i]][0]=pre[i];
				res[c[i]][1]=i;
				for (int j=pre[i];j<=i;j++) bl[j]++;
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d %d\n",res[i][0],res[i][1]);
	
}