#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
const int N=1000;
char s[N];
char t[N];
char a[N],b[N];
void solve() {
	scanf("%s%s",s,t);
	int n=0;
	int x=0;
	FOR(i,0,strlen(s)-1) {
		char c=s[i];
		if(c=='B') {
			x^=1;
		} else {
			a[++n]=c;
		}
		while(n>1 && a[n]==a[n-1]) n-=2;
	}
	int m=0;
	int y=0;
	FOR(i,0,strlen(t)-1) {
		char c=t[i];
		if(c=='B') {
			y^=1;
		} else {
			b[++m]=c;
		}
		while(m>1 && b[m]==b[m-1]) m-=2;
	}
	if(x==y && n==m) {
		FOR(i,1,n) {
			if(a[i]!=b[i]) {
				puts("NO");
				return ;
			}
		}
		puts("YES");
		return ;
	}
	puts("NO");
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}