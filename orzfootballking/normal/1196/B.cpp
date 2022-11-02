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
int a[200010],ans[200010];
int main() {
	int n,k,m,l,z;
	in(k);bool ff;
	for(int z=0;z<k;z++){
		ff=1;
		in(n);in(m);
		int t=0;
		for(int j=0;j<n;j++)in(a[j]);
		if(n==1&&m==1&&a[0]%2==0){
			cout<<"NO\n";continue;
		}
		int s=0,q=0;l=0;
		while(l<n){
			bool f=0;t=0;
			while(t%2==0&&l<n){
				t+=a[l];
				if(a[l]%2==1)f=1; 
				l++;
			}
			if(!f){
				cout<<"NO\n";ff=0;break;
			}
			
			while(a[l]%2==0&&l<n)l++;
			ans[s]=l;
			s++;
		}
		if(ff==0)continue;
		if(s<m||(s-m)%2==1){
			cout<<"NO";
		}else{
			cout<<"YES\n";
			for(int j=0;j<m-1;j++)out(ans[j]),putchar(' ');
			out(n);
		}
		putchar('\n');
	}
	return 0;
}