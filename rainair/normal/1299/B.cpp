#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
int x[MAXN],y[MAXN];
int n;

int main(){
	scanf("%d",&n);
	FOR(i,0,n-1) scanf("%d%d",x+i,y+i);
	if(n&1){
		puts("NO");return 0;
	}
	double X,Y;
	X = 1.0*(x[0]+x[n/2])/2.0;
	Y = 1.0*(y[0]+y[n/2])/2.0;
	// printf("%.10f %.10f",X,Y);
	FOR(l,1,n/2){
		int r = (l+n/2)%n;
		if(X != 1.0*(x[l]+x[r])/2.0 || Y != 1.0*(y[l]+y[r])/2.0){
			puts("NO");return 0;
		}
	}
	puts("YES");
	return 0;
}