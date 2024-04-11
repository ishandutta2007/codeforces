#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[1000010],stk[1000010],tp,ins[1000010],ans[1000010],m;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int qwqwq=gi();
	while(qwqwq--){
		int n=gi();tp=0;
		for(int i=1;i<=n;++i)a[i]=i-gi(),ins[i]=0;
		for(int i=1;i;i=a[i]){
			stk[++tp]=i;
			if(ins[i]){m=tp-ins[i];break;}
			ins[i]=tp;
		}
		printf("%d\n",m);
		for(int i=0;i<m;++i)printf("%d ",stk[tp-i]);puts("");
	}
	return 0;
}