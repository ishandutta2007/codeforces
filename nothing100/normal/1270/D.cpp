#include<bits/stdc++.h>
using namespace std;
int n,k,f[550],m,sma;
int main(){
	scanf("%d%d",&n,&k);
	int lasto,lastp;
	for (int i=1;i<=k+1;i++){
		printf("?");
		for (int j=1;j<=k+1;j++)
		if (i!=j)
		printf(" %d",j);
		printf("\n");
		fflush(stdout);
		int o,p;
		scanf("%d %d",&o,&p);
		if (i&&o!=lasto){
			f[i]=f[i-1]^1;
			if (p<lastp) sma=f[i-1];
			else if (p>lastp) sma=f[i];
		}
		else f[i]=f[i-1];
		lasto=o;
		lastp=p;
	}
	for (int i=1;i<=k+1;i++)
	if (f[i]==sma) m++;
	printf("! %d\n",m);
	fflush(stdout);
}