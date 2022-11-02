#include<bits/stdc++.h>
using namespace std;
int t,n,a[2000020],f[2000020],num[2000020],ans;
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		for (int i=0;i<=n;i++) num[i]=0,f[i]=0;
		for (int i=0;i<n;i++) num[a[i]]++;
		int sum=0;
		for (int i=1;i<=n;i++)
		if (num[i]){
			f[num[i]]++;
			sum++;
		}
		//printf("%d\n",sum);
		ans=n;
		int tmp1,tmp2;
		for (int i=1;i<=n;i++) f[i]=f[i]+f[i-1]; 
		for (int i=2;i<=n;i++){
			tmp1=tmp2=0;
			for (int j=0;j*i<n;j++){
				//printf("%d %d %d\n",(j+1)*i,max(j*i,(j+1)*i-j-2),f[(j+1)*i]-f[max(j*i,(j+1)*i-j-2)]);
				tmp1+=f[min((j+1)*i,n)]-f[min(n,max(j*i,(j+1)*i-j-2))];
				tmp2+=(f[min((j+1)*i,n)]-f[min(n,max(j*i,(j+1)*i-j-2))])*(j+1);
			}
			if (tmp1==sum) ans=min(ans,tmp2);
		}
		printf("%d\n",ans);
	}
}