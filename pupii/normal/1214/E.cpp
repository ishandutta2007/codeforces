#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int L[200010],c,d[100010],s[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=n;for(int i=1;i<=n;++i)d[i]=gi(),s[i]=i;
	std::sort(s+1,s+n+1,[&](int a,int b){return d[a]>d[b];});
	for(int i=1;i<=n;++i)L[i]=s[i]*2;
	for(int i=1;i<n;++i)printf("%d %d\n",L[i],L[i+1]);
	for(int i=1,x;i<=n;++i){
		x=L[i];
		printf("%d %d\n",L[i+d[x>>1]-1],x-1);
		if(i+d[x>>1]-1==m)L[++m]=x-1;
	}
	return 0;
}