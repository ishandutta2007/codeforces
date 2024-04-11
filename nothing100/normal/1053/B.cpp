#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n;
int a[300030],b[2][300030];
LL res;
int calc(LL x){
	int res=0;
	while (x){
		if (x&1) res++;
		x/=2;
	}
	return res;
}
int main(){
	//freopen("A.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		LL tmp;
		scanf("%lld",&tmp);
		a[i]=calc(tmp);
	}
	LL sum=0;
	b[0][0]=1;
	for (int i=1;i<=n;i++){
		int tmp=a[i],ma=a[i];
		for (int j=1;j<149;j++)
		if (i-j>0){
			tmp+=a[i-j];
			if (a[i-j]>ma) ma=a[i-j];
			if (ma*2<=tmp&&tmp%2==0) res++;  
		}
		sum+=a[i];
		b[0][i]=b[0][i-1];
		b[1][i]=b[1][i-1];
		b[sum&1][i]++;
		if (i>=150){
			res+=b[sum&1][i-150];
		}
		//printf("%lld\n",res);
	}
	//for (int i=0;i<=n;i++) printf("%d %d\n",b[0][i],b[1][i]);
	printf("%lld\n",res);
}