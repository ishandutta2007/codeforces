#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 300005;
int n, cnt;
char s[N];
int main() {
	scanf("%d%s", &n, s+1);
	if(n&1) return puts(":("), 0;
	if(s[1]==')' || s[n]=='(') return puts(":("), 0;
	s[1]='(', s[n]=')';
	for(int i=2; i<n; ++i) cnt+=s[i]=='(';
	for(int i=2; i<=n; ++i) if(s[i]=='?') s[i]=(cnt<n/2-1?++cnt, '(':')');
	cnt=0;
	for(int i=2; i<n; ++i){
		cnt+=(s[i]=='('?1:-1);
		if(cnt<0) return puts(":("), 0;
	}
	if(cnt) return puts(":("), 0;
	puts(s+1);
	return 0;
}