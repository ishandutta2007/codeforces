#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int f[5010][5010],c[5010],a[5010];
int main(){
	int N=gi(),n=0;
	for(int i=1;i<=N;++i)a[i]=gi();
	for(int i=1;i<=N;++i)if(a[i]!=a[i-1])c[++n]=a[i];
	for(int s=2;s<=n;++s){
		for(int l=1;l+s-1<=n;++l){
			int r=l+s-1;
			if(c[l]==c[r])f[l][r]=f[l+1][r-1]+1;
			else f[l][r]=std::min(f[l+1][r],f[l][r-1])+1;
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}