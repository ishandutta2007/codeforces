#include<cstdio>
const int prm=19260817;
int n,m,now=prm;
int main(){
	scanf("%d%d",&n,&m);
	if(m==1){
		printf("%d %d\n%d %d %d\n",2,2,1,2,2);
		return 0;
	}
	printf("%d %d\n",2,prm);
	printf("%d %d %d\n",1,n,2); now-=2;
	for(int i=1;i<=n-3;++i){
		printf("%d %d %d\n",i,i+1,2); now-=2;
	}
	printf("%d %d %d\n",n-2,n-1,now); m-=n-1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			if(i==1){
				if(j==n||j==2) continue;
			}else if(i!=n-1){
				if(j==i+1) continue;
			}
			if(!m--) return 0;
			printf("%d %d %d\n",i,j,now);
		}
	return 0;
}