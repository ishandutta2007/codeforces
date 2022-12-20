#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e3+5;
int n,a,b;
double p[maxn],u[maxn];
double dp[maxn][maxn];
int c[maxn][maxn];
void check(double k){
	for(int i=n-1;i>=0;i--) for(int j=0;j<=b;j++){
		dp[i][j]=dp[i+1][j];
		c[i][j]=c[i+1][j];
		if(j){
			if(dp[i][j]<dp[i+1][j-1]+u[i]){
				dp[i][j]=dp[i+1][j-1]+u[i];
				c[i][j]=c[i+1][j-1];
			}
			if(dp[i][j]<dp[i+1][j-1]+1-(1-p[i])*(1-u[i])+k){
				dp[i][j]=dp[i+1][j-1]+1-(1-p[i])*(1-u[i])+k;
				c[i][j]=c[i+1][j-1]+1;
			}
		}
		if(dp[i][j]<dp[i+1][j]+p[i]+k){
			dp[i][j]=dp[i+1][j]+p[i]+k;
			c[i][j]=c[i+1][j]+1;
		}
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	a=readint();
	b=readint();
	for(int i=0;i<n;i++) scanf("%lf",&p[i]);
	for(int i=0;i<n;i++) scanf("%lf",&u[i]);
	double l=-1,r=0;
	while(r-l>1e-6){
		double mid=l+(r-l)/2;
		check(mid);
		if(c[0][b]<a) l=mid;
		else r=mid;
	}
	check(r);
	printf("%f\n",dp[0][b]-r*a);
	return 0;
}