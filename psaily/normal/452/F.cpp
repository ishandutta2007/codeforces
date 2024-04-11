#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long ull;

const int N=3e5+5;
int n,a[N];
ull pw[N];

struct bits {
	int lowbit(int x){return x&-x;}
	ull sum[N];
	void update(int x) {
		for (ull v=pw[n-x+1];x<=n;x+=lowbit(x)) sum[x]+=v;
	}
	ull query(int x) {
		ull res=0;
		for (;x;x-=lowbit(x)) res+=sum[x];
		return res;
	}
	ull hsh(int l,int r) {
		ull res=0;
		res=query(r)-query(l-1);
		return res;
	}
}bit[2];

int main() {
	pw[0]=1;
	rep(i,1,N) pw[i]=pw[i-1]*3;
	
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);
	rep(i,1,n+1) {
		// (a[i]+1,n) (a[i]-p,a[i])
		
		int mi=min(a[i]-1,n-a[i]);
		ull hsh1=bit[0].hsh(a[i]-mi,a[i]);
		int p=n-a[i]+1;
		ull hsh2=bit[1].hsh(p-mi,p);
		
		if (a[i]-1<n-a[i]) hsh2*=pw[abs(n-a[i]-a[i]+1)];
		else hsh1*=pw[abs(n-a[i]-a[i]+1)];
		
		// bug(i),bug(mi),bug(hsh1),debug(hsh2);
		
		if (hsh1!=hsh2) return puts("YES"),0;
		
		bit[0].update(a[i]);
		bit[1].update(p);	
	}
	puts("NO");
	return 0;	
}