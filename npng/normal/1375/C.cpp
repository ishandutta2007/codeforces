#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=300000;
int n;
int a[Maxn+5];
int minn[Maxn+5],maxn[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		bool flag=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		/*minn[1]=a[1];
		for(int i=2;i<=n;i++){
			minn[i]=min(minn[i-1],a[i]);
		}
		maxn[n]=a[n];
		for(int i=n-1;i>0;i--){
			maxn[i]=max(maxn[i+1],a[i]);
		}
		for(int i=1;i<n;i++){
			if(minn[i]>maxn[i+1]){
				flag=0;
				break;
			}
		}*/
		if(a[1]<a[n]){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}
/*
7
6 5 4 2 7 1 3
*/