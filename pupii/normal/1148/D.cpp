#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
struct data{int a,b,i;};
std::vector<data>A,B;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i){
		data x;x.a=gi(),x.b=gi(),x.i=i;
		if(x.a<x.b)A.push_back(x);
		else B.push_back(x);
	}
	if(A.size()>B.size()){
		std::sort(A.begin(),A.end(),[](const data&a,const data&b){return a.b>b.b;});
		printf("%d\n",A.size());
		for(auto i:A)printf("%d ",i.i);
	}else{
		std::sort(B.begin(),B.end(),[](const data&a,const data&b){return a.b<b.b;});
		printf("%d\n",B.size());
		for(auto i:B)printf("%d ",i.i);
	}
	return 0;
}