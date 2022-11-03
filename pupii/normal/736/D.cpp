#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int px[500010],py[500010];
std::bitset<4001>A[2001];
int main(){
	int n=gi(),m=gi();
	for(int i=1;i<=m;++i)px[i]=gi(),py[i]=gi(),A[px[i]][py[i]]=1;
	for(int i=1;i<=n;++i)A[i][i+n]=1;
	for(int i=1;i<=n;++i){
		int p=i;
		for(int j=i;j<=n;++j)if(A[j][i]){p=j;break;}
		std::swap(A[i],A[p]);
		for(int j=1;j<=n;++j)if(j!=i&&A[j][i])A[j]^=A[i];
	}
	for(int i=1;i<=m;++i)puts(A[py[i]][px[i]+n]?"NO":"YES");
	return 0;
}