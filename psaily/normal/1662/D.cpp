#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl 
mt19937 mrand(time(0)); 

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head
const int N=2e5+5;
char s1[N],s2[N];
int n,m;
int a[N],b[N],at,bt,acnt,bcnt;

void solve() {
	scanf("%s%s",s1+1,s2+1);	
	int n=strlen(s1+1),m=strlen(s2+1);
	at=bt=acnt=bcnt=0;
	rep(i,1,n+1) {
		int c=s1[i]-'A';
		if (at&&c==a[at]) at--;
		else {
			if (c==1) acnt++;
			else { a[++at]=c; }
		}
	}
	rep(i,1,m+1) {
		int c=s2[i]-'A';
		if (bt&&c==b[bt]) bt--;
		else {
			if (c==1) bcnt++;
			else { b[++bt]=c; }
		}
	}
	if (acnt%2!=bcnt%2) puts("NO");
	else {
		// bug(at),debug(bt);
		if (at!=bt) puts("NO");
		else {
			bool ok=1;
			rep(i,1,at+1) ok&=a[i]==b[i];
			puts(ok?"YES":"NO");
		}
	}
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}

	return 0;
}