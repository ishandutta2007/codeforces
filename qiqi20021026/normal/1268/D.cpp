#include<bits/stdc++.h>

using namespace std;

#define N 2200

int n,in[N],out[N],d[N],ans[N],sum;
bool a[N][N];
char s[N];

bool check(){
	sort(d+1,d+n+1);
	for (int i=1;i<n;++i){
		d[i]+=d[i-1];
		if (d[i]==i*(i-1)/2) return 0;
	}
	return 1;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%s",s+1);
		for (int j=1;j<=n;++j){
			a[i][j]=s[j]-'0';
			out[i]+=a[i][j];
		}
		in[i]=n-out[i]-1;
	}
	if (n<=6){
		for (int i=0;i<1<<n;++i){
			int cnt=0;
			for (int j=0;j<n;++j) cnt+=i>>j&1;
			for (int j=1;j<=n;++j){
				d[j]=0;
				for (int k=1;k<=n;++k){
					if (j!=k) d[j]+=a[j][k]^(i>>(j-1)&1)^(i>>(k-1)&1);
				}
			}
			if (check()) ++ans[cnt];
		}
		for (int i=0,fac=1;i<=n;fac*=++i){
			if (ans[i]){
				printf("%d %d\n",i,ans[i]*fac);
				return 0;
			}
		}
		puts("-1");
		return 0;
	}
	for (int i=1;i<=n;++i) d[i]=out[i];
	if (check()){
		puts("0 1");
		return 0;
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			if (j==i) d[j]=in[j];
			else d[j]=out[j]+(a[i][j]?1:-1);
		}
		if (check()) ++sum;
	}
	printf("1 %d\n",sum);
	
	return 0;
}