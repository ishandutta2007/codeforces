#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int a[1010][1010];
int H[1010][1010],lH[1010],W[1010][1010],lW[1010];
int main(){
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=H[i][j]=W[j][i]=gi();
	for(int i=1;i<=n;++i)std::sort(H[i]+1,H[i]+m+1),lH[i]=std::unique(H[i]+1,H[i]+m+1)-H[i]-1;
	for(int i=1;i<=m;++i)std::sort(W[i]+1,W[i]+n+1),lW[i]=std::unique(W[i]+1,W[i]+n+1)-W[i]-1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			int h1=std::upper_bound(H[i]+1,H[i]+lH[i]+1,a[i][j]-1)-H[i]-1,h2=std::upper_bound(H[i]+1,H[i]+lH[i]+1,a[i][j])-H[i]-1;
			int w1=std::upper_bound(W[j]+1,W[j]+lW[j]+1,a[i][j]-1)-W[j]-1,w2=std::upper_bound(W[j]+1,W[j]+lW[j]+1,a[i][j])-W[j]-1;
			printf("%d ",std::max(h1,w1)+std::max(lH[i]-h2,lW[j]-w2)+1);
		}
		puts("");
	}
	return 0;
}