#include<bits/stdc++.h>
using namespace std;
long long f[2][2];char a[100005],b[100005];int n;
long long C(long long x){return 1ll*x*(x-1)/2LL;}
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	for (int i=1;i<=n;i++)
		f[a[i]-'0'][b[i]-'0']++;
	long long ans1=0,ans2=0;
	for (int u=0;u<2;u++)
		for (int v=0;v<2;v++)
			for (int p=0;p<2;p++)
				for (int q=0;q<2;q++)
					if ((v|p)!=(u|v)||(u|q)!=(p|q)){
						if (u!=p||v!=q)
							ans1+=f[u][v]*f[p][q];
						else
							ans2+=C(f[u][v]);
					}
	printf("%I64d\n",ans1/2+ans2);
}