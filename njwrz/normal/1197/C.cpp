#include<bits/stdc++.h>
using namespace std;
inline void in(int &x) {
	x=0;
	int f=1;
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
int n,m,a[300005],q[300005];
int main() {
	in(n);in(m);
	for(int i=1;i<=n;i++)in(a[i]);
	for(int i=2;i<=n;i++)q[i-1]=a[i]-a[i-1];
	sort(q+1,q+n,greater<int>());
	int ans=a[n]-a[1];
	for(int i=1;i<m;i++)ans-=q[i];
	cout<<ans;
	return 0;
}