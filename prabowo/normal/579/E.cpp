#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MOD7 10000000007
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-12
#define pi acos(-1)
#define sqr(x) x*x
#define kevin using
#define keren namespace
#define abiez std
#define SYNC ios_base::sync_with_stdio(0)
#define lol ;
#define tulis cout <<
#define ok << endl

kevin keren abiez;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
int n,arr2[200005];
long double ki,ka,mid,tmp,tmp2,ans,arr[200005];
long double kadane[200005],kadane2[200005];
long double cek(long double x) {
	long double ret = 0;
	kadane[0] = max((long double)0,arr[0]-x);
	kadane2[0] = min((long double)0,arr[0]-x);
	for (int i=0;i<n;i++) {
		kadane[i] = max((long double)0,kadane[i-1] + arr[i]-x);
		kadane2[i] = min((long double)0,kadane2[i-1] + arr[i]-x);
		ret = max(ret,max(abs(kadane[i]),abs(kadane2[i])));
//		if (x == 2.66667) cout << i <<" "<<kadane[i]<<" "<<kadane2[i]<<" "<<arr[i]-x<<endl;
	}
	return ret;
}

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",&arr2[i]);
		arr[i] = arr2[i];
	}
	ki = -10000;
	ka = 10000;
	ans = INF;
	for (int i=0;i<60;i++) {
		mid = (ki+ka)/2;
		tmp = cek(mid);
		tmp2 = cek(mid+EPS);
	//	cout << tmp <<" "<<tmp2;
	//	printf(" %.15Lf %.15Lf %.15Lf\n",ki,ka,mid);
		if (tmp < tmp2) {
			ans = min(ans,tmp);
			ka = mid-EPS;
		}else if (tmp > tmp2) {
			ans = min(ans,tmp2);
			ki = mid+EPS;
		}
	}
//	cout << cek(2.66667)<<endl;
	printf("%.15lf\n",(double)ans);
}