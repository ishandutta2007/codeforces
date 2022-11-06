#include<cstdio>
int n,a,b;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;i<=n;++i)
		if(i%a==0&&(n-i)%b==0){
			for(int j=1;j<=i;j+=a)
				for(int k=0;k<a;++k)
					printf("%d ",j+(k+1)%a);
			for(int j=i+1;j<=n;j+=b)
				for(int k=0;k<b;++k)
					printf("%d ",j+(k+1)%b);
			return 0;
		}
	printf("-1");
}