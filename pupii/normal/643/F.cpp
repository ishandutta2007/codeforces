#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,p,q;
unsigned cn[134],A[134];
unsigned f(unsigned d){
	unsigned ret=0,pw=1;
	for(int i=0;i<=p&&i<n;++i,pw*=d)ret+=cn[i]*pw;
	return ret*d;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),p=gi(),q=gi();unsigned ans=0;
	for(int i=0;i<=p;++i){
		for(int j=1;j<=i;++j)A[j]=n-j+1;
		for(int j=1;j<=i;++j){
			unsigned x=j;
			for(int k=1;k<=i;++k){
				unsigned t=std::__gcd(A[k],x);
				x/=t,A[k]/=t;
			}
		}
		cn[i]=1;for(int j=1;j<=i;++j)cn[i]=cn[i]*A[j];
	}
	for(int i=1;i<=q;++i)ans^=f(i);
	printf("%u\n",ans);
	return 0;
}