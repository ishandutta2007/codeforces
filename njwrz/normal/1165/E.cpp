#include <bits/stdc++.h>
using namespace std;
inline void in(long long &x) {
	x=0;
	long long f=1;
	char s=getchar();
	while(s<'0'||s>'9') {
		if(s=='-')
			f=-1;
		s=getchar();
	}
	while(s>='0'&&s<='9') {
		x=x*10+s-48;
		s=getchar();
	}
	x*=f;
}
inline void out(int x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9)
		out(x/10);
	putchar(x%10+48);
}
long long i,n,a[200005],b[200005];
int main(){
	in(n);
	for(i=1;i<=n;i++)in(a[i]);
	for(i=1;i<=n;i++)in(b[i]);
	for(i=1;i<=n;i++){
		a[i]=a[i]*i*(n-i+1);
	}
	sort(a+1,a+n+1);sort(b+1,b+n+1,greater<int>());
	long long ans=0;
	for(i=1;i<=n;i++){
		a[i]=a[i]%998244353;
		ans+=a[i]*b[i];
		ans=ans%998244353;
	}
	out(ans);
	return 0;
}