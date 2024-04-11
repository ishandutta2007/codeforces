#include<cstdio>
#include<algorithm>
#include<cstring>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define F2(i,a,b) for(int i=a;i<b;++i)
int n,mi,ans=0,anss[500];
int main(){
	scanf("%d",&n);
	mi=std::max(n-100,1);
	F(i,mi,n){
		int sum=i, j=i;
		while(j){
			sum+=j%10;
			j/=10;
		}
		if(sum==n) anss[++ans]=i;
	}
	printf("%d\n",ans);
	F(i,1,ans){
		printf("%d\n",anss[i]);
	}
	return 0;
}