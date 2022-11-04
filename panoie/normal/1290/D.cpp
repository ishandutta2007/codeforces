#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2333;
int n, k, s, ans, cnt;
bool f[N];
bool ask(int x){
	// ++cnt;
	// return 0;
	printf("? %d\n", x), fflush(stdout);
	char c;
	while(!isalpha(c=getchar()));
	return c=='Y';
}
int main() {
	scanf("%d%d", &n, &k);
	if(k==1){
		for(int i=1; i<=n; ++i){
			bool o=0;
			for(int j=1; j<i; ++j){
				ask(j);
				o|=ask(i);
			}
			ans+=!o;
		}
		printf("! %d\n", ans), fflush(stdout);
		return 0;
	}
	k/=2, s=n/k;
	for(int i=1; i<s; ++i) for(int j=1; j<=s-i && j<=i; ++j){
		printf("R\n"), fflush(stdout);
		for(int x=j; x<=s; x+=i){
			// printf("[%d]", x);
			for(int y=(x-1)*k+1; y<=x*k; ++y) f[y]|=ask(y);
		}
	}
	for(int i=1; i<=n; ++i) ans+=!f[i];
	printf("! %d\n", ans), fflush(stdout);
	// printf(">> %d %d\n", cnt, 3*n*n/k/4);
	return 0;
}