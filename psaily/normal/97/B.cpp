#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

void chkmax(int &a,int b){if(a<b)a=b;}
void chkmin(int &a,int b){if(a>b)a=b;}

const int N=2e5+5;
int n,m;
pii a[N];

void solve(int l,int r) {
	if (l>=r) return;
	int mid=(l+r)>>1;
	solve(l,mid-1);
	solve(mid+1,r);
	rep(i,l,r+1) a[++m]=mp(a[mid].fi,a[i].se);
}

int main() {
	cin>>n; m=n;
	rep(i,1,n+1) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+1+n);
	solve(1,n);
	sort(a+1,a+1+m);
	m=unique(a+1,a+1+m)-a-1;
	printf("%d\n",m);
	rep(i,1,m+1) printf("%d %d\n",a[i].fi,a[i].se);
	return 0;	
}