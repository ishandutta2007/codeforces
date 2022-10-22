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
int main() {
	int n,m;
	in(n);in(m);
	int ans=1;
	for(int i=1;i<=n+m;i++){
		ans*=2;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}