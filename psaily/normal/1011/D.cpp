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


const int N=1005;

int n,mx;
int ok[N];

int query(int y) {
    printf("%d\n",y);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    if (!x||x==-2) exit(0);
    return x;
}

int main() {
	scanf("%d%d",&mx,&n);
	rep(i,0,n) ok[i]=query(1),ok[i]=(ok[i]==1)?1:0;
	int l=1,r=mx,nw=0;
	while (l<=r) {
		int mid=(l+r)>>1;
		int res=query(mid);
		if (ok[nw]) {
			if (res==-1) r=mid-1;
			else l=mid+1;
		}else {
			if (res==-1) l=mid+1;
			else r=mid-1;	
		}
		nw=(nw+1)%n;
	}
	
	return 0;	
}