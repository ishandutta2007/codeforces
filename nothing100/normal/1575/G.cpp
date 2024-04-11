#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000;
const int mo=1000000007;
int n,a[100010],phi[100010],num[100010],po[100010],tot;
LL res,ans;
vector<int> ys[100010];
void init(){
	for (int i=1;i<=maxn;i++)
	for (int j=i;j<=maxn;j+=i) ys[j].push_back(i);
	phi[1]=1;
	for (int i=2;i<=maxn;i++){
		int tmp=1,tmpp=i;
		while (tmpp%ys[i][1]==0){
			tmpp/=ys[i][1];
			tmp*=ys[i][1];
		}
		if (tmpp==1) phi[i]=(ys[i][1]-1)*(i/ys[i][1]);
		else phi[i]=phi[tmp]*phi[tmpp];
	}
}
void ins(int x,int y){
	//printf("%d %d\n",x,y);
	for (int i=0;i<ys[x].size();i++){
		res=(res-1ll*phi[ys[x][i]]*num[ys[x][i]]*num[ys[x][i]])%mo;
		num[ys[x][i]]+=y;
		res=(res+1ll*phi[ys[x][i]]*num[ys[x][i]]*num[ys[x][i]])%mo;
	}
}
int main(){
	init();
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	//for (int i=1;i<=10;i++) printf("%d\n",phi[i]);
	for (int i=1;i<=n;i++){
		tot=0;
		for (int j=i;j<=n;j+=i) po[tot++]=a[j];
		sort(po,po+tot);
		int k=0;
		for (int j=0;j<tot;j=k){
			while (k<tot&&po[k]==po[j]) k++;
			ins(po[j],k-j);
		}
		ans=(ans+res*phi[i])%mo;
		k=0;
		for (int j=0;j<tot;j=k){
			while (k<tot&&po[k]==po[j]) k++;
			ins(po[j],j-k);
		}
	}
	ans=(ans+mo)%mo;
	printf("%lld\n",ans);
}