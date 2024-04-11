#include <bits/stdc++.h>
#define ft(i,a,b) for(int i=(a); i<=(b); ++i)
#define fd(i,a,b) for(int i=(a); i>=(b); --i)
#define fv(i,v) for(size_t i=0; i<(v).size(); ++i)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define OP operator
#define LB lower_bound
#define UB upper_bound
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const int N=105;
int n,m,a[N][N];
int s[N];

int getmx(int x){
	ft(i,1,m) s[i]=a[i][x]-a[i][n];
	sort(s+1,s+m+1);
	reverse(s+1,s+m+1);
	ft(i,2,m) s[i]+=s[i-1];
	int t=0;
	while (t<m && s[t+1]>=0) t++;
	return t;
}

PII p[N];

int main(){
	scanf("%d%d",&n,&m);
	ft(i,1,m) ft(j,1,n) scanf("%d",&a[i][j]);
	int ansx=1, mx=getmx(1);
	ft(x,2,n-1){
		int y=getmx(x);
		if (y>mx){
			mx=y;
			ansx=x;
		}
	}
	ft(i,1,m) p[i]=MP(a[i][ansx]-a[i][n],i);
	sort(p+1,p+m+1);
	reverse(p+1,p+m+1);
	printf("%d\n",m-mx);
	ft(i,mx+1,m){
		printf("%d",p[i].S);
		putchar(i<m?' ':'\n');
	}
	return 0;
}