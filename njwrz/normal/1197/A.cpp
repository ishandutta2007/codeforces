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
	int n,i,j,l;
	in(n);
	for(i=1;i<=n;i++){
		in(l);
		int max1=0,max2=0,x;
		for(j=0;j<l;j++){
			in(x);
			if(x>max1)max2=max1,max1=x;
			else if(x<=max1&&x>max2)max2=x;
		}
		out(min(max2-1,l-2));
		putchar('\n');
	}
	return 0;
}