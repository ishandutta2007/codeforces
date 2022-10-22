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
int a[200005];
int main() {
	int n,i,maxi=0,p=-1;
	in(n);
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxi){
			maxi=a[i];p=i;
		}
	}
	for(i=p-1;i>=0;i--){
		if(a[i]>=a[i+1]){
			cout<<"NO";return 0;
		}
	}
	for(i=p+1;i<n;i++){
		if(a[i]>=a[i-1]){
			cout<<"NO";return 0;
		}
	}
	cout<<"YES";
	return 0;
}