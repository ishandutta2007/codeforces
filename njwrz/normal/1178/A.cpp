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
	int n,a[101],t=0;
	in(n);
	for(int i=1;i<=n;i++){
		in(a[i]);t+=a[i];
	}
	t=t/2+1;
	int ans[101],q=a[1],l=1;
	ans[1]=1;
	for(int i=2;i<=n;i++){
		if(a[i]*2<=a[1]){
			ans[++l]=i;q+=a[i];
		} 
		if(q>=t){
			out(l);putchar('\n');
			for(int j=1;j<=l;j++){
				out(ans[j]);putchar(' ');
			} 
			return 0;
		}
	}
	putchar('0');
	return 0;
}