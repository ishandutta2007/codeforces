#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N=1e6+50;
char a[N];
int cnt[30];
void solve() {
	scanf("%s",a);
	int n=strlen(a);
	memset(cnt,0,sizeof(cnt));
	FOR(i,0,n-1) cnt[a[i]-'a']++;
	int p=0;
	while(p<n) {
		if(cnt[a[p]-'a']>1) {
			--cnt[a[p]-'a'];
			++p;
		} else break;
	}
	printf("%s\n",a+p);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}