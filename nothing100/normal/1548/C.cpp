#include<bits/stdc++.h>
#define LL long long
#define fi first
#define se second
using namespace std;
const int mo=1000000007;
const int ny3=333333336;
int n,q,ans[200020],g[3],qz[3000030],nqz[3000030],tmp[3];
pair<int,int> ques[200020];
int ksm(int x,int y){
	int res=1;
	while (y){
		if (y&1) res=1ll*res*x%mo;
		x=1ll*x*x%mo;
		y>>=1;
	}
	return res;
}
int calc(int x,int y){//x<y
	return 1ll*qz[y]*nqz[x]%mo*nqz[y-x]%mo;
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=0;i<q;i++){
		int o;
		scanf("%d",&o);
		ques[i].fi=o;
		ques[i].se=i;
	}
	qz[0]=1;
	nqz[0]=1;
	for (int i=1;i<=3*n+1;i++) qz[i]=1ll*qz[i-1]*i%mo;
	nqz[3*n+1]=ksm(qz[3*n+1],mo-2);
	for (int i=3*n;i;i--) nqz[i]=1ll*nqz[i+1]*(i+1)%mo;
	sort(ques,ques+q);
	int tail=0;
	g[0]=g[1]=g[2]=n;
	for (int i=1;i<=3*n;i++){
		tmp[2]=(((calc(i+1,3*n+1)-g[2]*2ll-g[1])%mo*ny3)%mo+mo)%mo;
		tmp[1]=(tmp[2]+g[2])%mo;
		tmp[0]=(tmp[1]+g[1])%mo;
		for (int j=0;j<3;j++) g[j]=tmp[j];
		while (tail<q&&ques[tail].fi<i) tail++;
		while (tail<q&&ques[tail].fi==i){
			ans[ques[tail].se]=g[0];
			tail++;
		}
	}
	for (int i=0;i<q;i++) printf("%d\n",ans[i]);
}