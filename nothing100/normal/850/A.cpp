#include<bits/stdc++.h>
using namespace std;
int a[1010][5],n,f[1010],que[3],ans;
int check(int x,int y,int z){
	int tmp=0;
	for (int i=0;i<5;i++) tmp+=(a[y][i]-a[x][i])*(a[z][i]-a[x][i]);
	if (tmp>0) return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	for (int j=0;j<5;j++)
	scanf("%d",&a[i][j]);
	if (n<3){
		printf("%d\n",n);
		for (int i=0;i<n;i++) printf("%d ",i+1);
	}
	else{
		int cnt=0;
		for (int i=0;i<n;i++){
			que[cnt++]=i;
			if (cnt==3){
				f[que[0]]|=check(que[0],que[1],que[2]);
				f[que[1]]|=check(que[1],que[0],que[2]);
				f[que[2]]|=check(que[2],que[0],que[1]);
				cnt=0;
				for (int j=0;j<3;j++)
				if (!f[que[j]]) que[cnt++]=que[j];
			}
		}
		for (int i=0;i<n;i++)
		if (!f[i]){
			for (int j=0;j<n;j++)
			if (j!=i){
				for (int k=j+1;k<n;k++)
				if (k!=i) f[i]|=check(i,j,k);
			}
		}
		for (int i=0;i<n;i++)
		if (!f[i]) ans++;
		printf("%d\n",ans);
		for (int i=0;i<n;i++)
		if (!f[i]) printf("%d ",i+1);
	}
}