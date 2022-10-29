#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
// head

const int N=2e5+50;
int n,m,c;
pii a[N];

void chkmin(int &a,int b) {if (a>b) a=b;}

bool cmp(pii a,pii b) {return abs(a.fi)<abs(b.fi);}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i].fi),a[i].se=i,c+=a[i].fi<0;
	sort(a+1,a+1+n,cmp);
	int pos=1,f=0,cnt=0;
	if (a[1].fi==0) f=1;
	if (f) {
		rep(i,2,n+1) {
			if (a[i].fi==0) printf("1 %d %d\n",a[i].se,a[1].se),cnt++;
			else {pos=i; break;}
		}
		if (a[n].fi==0) pos=n+1;
	}
	bool fir=1; int p=0,res=0;
	if (c%2==1) {
		rep(i,pos,n+1) if (a[i].fi<0&&fir) fir=0,p=i;
		if (f) printf("1 %d %d\n",a[p].se,a[1].se),cnt++,res=a[1].se;
		else res=a[p].se;
	}else if (f) res=a[1].se;
	if (pos==p) pos++;
	// debug(pos);
	rep(i,pos+1,n+1) if (i!=p) printf("1 %d %d\n",a[i].se,a[pos].se),cnt++;
	if (res&&cnt<n-1) printf("2 %d\n",res);
	return 0;
}