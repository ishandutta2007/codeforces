#include <algorithm>
#include <functional>
#include <stdio.h>
#define cmax(x, y) ((y)>x?x=(y),1:0)
int F() {
	register int a;
	register char c;
	while(c=getchar(), c<'0'||c>'9');
	for(a=c-'0'; c=getchar(), c>='0'&&c<='9'; a=a*10+c-'0');
	return a;
}
const int N=2e5, M=2e6+5, P=1e9+7;
int p[N], q[N], mp[M], pr[M], times[M], maxcnt[M];
void clcm(register int x) {
	register int id, cur, cnt;
	while(x!=1) {
		cur=pr[id=mp[x]];
		for(cnt=0; x%cur==0; x/=cur) ++cnt;
		if(times[id]==cnt) ++maxcnt[id];
		if(cmax(times[id], cnt)) maxcnt[id]=1;
	}
}
bool check(register int x) {
	register int id, cur, cnt;
	register bool ans=1;
	while(x!=1) {
		cur=pr[id=mp[x]];
		for(cnt=0; x%cur==0; x/=cur) ++cnt;
		if(times[id]==cnt && maxcnt[id]==1) ans=0;
	}
	return ans;
}
int main() {
	register int n, m, i, j, cnt=0, ans=1;
	register bool inc=0;
	n=F();
	for(i=0; i<n; ++i) p[i]=F();
	std::sort(p, p+n, std::greater<int>());
	m=p[0];
	for(i=2; i<=m; ++i) {
		if(!mp[i]) pr[mp[i]=++cnt]=i;
		for(j=1; j<=cnt && i*pr[j]<=m; ++j) {
			mp[i*pr[j]]=j;
			if(i%pr[j]==0) break;
		}
	}
	for(i=0; i<n; ++i) clcm(q[i] =p[i]-(bool)times[mp[p[i]]]);
	for(i=1; i<=cnt; ++i) {
		for(j=1; j<=times[i]; ++j) {
			ans=(long long)ans*pr[i]%P;
		}
	}
	for(i=0; i<n; ++i) inc|=check(q[i]);
	printf("%d\n", (ans+inc)%P);
	return 0;
}