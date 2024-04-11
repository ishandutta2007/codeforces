#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
char S[20];
int s[20],a[20],b[20];
main(){
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	int n=gi(),ans=0,a=0,b;
	for(int i=9;i<=n;i*=10)if(a+i<=n)a+=i;
	b=n-a;
	while(a)ans+=a%10,a/=10;
	while(b)ans+=b%10,b/=10;
	printf("%lld\n",ans);
	return 0;
}