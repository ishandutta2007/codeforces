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
inline void out(long long x) {
	if(x<0) {
		putchar('-');
		x=-x;
	}
	if(x>9)
		out(x/10);
	putchar(x%10+48);
}
long long a[1000005],n;
inline void voi(){
	priority_queue<long long > q;
	while(!q.empty())q.pop();
	in(n);
	for(int i=1;i<=n;i++)in(a[i]);
	sort(a+1,a+n+1);
	long long t=a[1]*a[n];
	for(int i=2;i<=n/2;i++){
		if(a[i]*a[n-i+1]!=t){
			puts("-1\n");return ;
		}
	}
	for(long long i=2;i*i<=t;i++){
		if(t%i==0){
			q.push(i);if(i*i!=t)q.push(t/i);
		}
	}
	if(q.size()!=n){
		puts("-1\n");return ;
	}
	for(int i=n;i>=1;i--){
		if(a[i]!=q.top()){
			puts("-1\n");return ;
		}
		q.pop();
	}
	out(t);putchar('\n');
}
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)voi();
	return 0;
}