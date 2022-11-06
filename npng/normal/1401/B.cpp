#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x_1,y_1,z_1;
		int x_2,y_2,z_2;
		scanf("%d%d%d%d%d%d",&x_1,&y_1,&z_1,&x_2,&y_2,&z_2);
		int ans=0,tmp;
		tmp=min(z_1,y_2);
		ans+=tmp*2;
		z_1-=tmp;
		y_2-=tmp;
		tmp=min(z_1,z_2);
		z_1-=tmp;
		z_2-=tmp;
		if(x_1+z_1<z_2){
			tmp=min(z_2-x_1-z_1,y_1);
			ans-=tmp*2;
		}
		printf("%d\n",ans);
	}
	return 0;
}