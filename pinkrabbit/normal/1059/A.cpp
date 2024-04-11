#include<cstdio>
// from_luogu
int n,L,a,t[100005],l[100005],Ans;

int main(){
	scanf("%d%d%d",&n,&L,&a);
	for(int i=1;i<=n;++i) scanf("%d%d",t+i,l+i);
	t[++n]=L;
	for(int i=1;i<=n;++i) Ans+=(t[i]-t[i-1]-l[i-1])/a;
	printf("%d",Ans);
	return 0;
}