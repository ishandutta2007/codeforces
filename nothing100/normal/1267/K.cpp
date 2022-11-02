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

const int N=60;

LL c[N][N];

void init_c(){
	ft(i,0,N-1){
		c[i][0]=1;
		ft(j,1,i) c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}

int a[N],top;

void solve(){
	top=0;
	LL k; scanf("%lld",&k);
	while (k){
		top++;
		a[top]=k%(top+1);
		k/=top+1;
	}
	sort(a+1,a+top+1);
	//ft(i,1,top) printf("a[%d]=%d\n",i,a[i]);
	LL ans1=1;
	for(int i=1; i<=top; ){
		int j=i; while (j<top && a[j]==a[j+1]) j++;
		ans1*=c[j-max(a[i]-1,0)][j-i+1];
		//printf("%d %d\n",j-max(a[i]-1,0),j-i+1);
		i=j+1;
	}
	if (a[1]){
		printf("%lld\n",ans1-1);
		return;
	}
	LL ans2=1;
	a[1]=top;
	sort(a+1,a+top+1);
	//ft(i,1,top-1) a[i]=a[i+1];
	//top--;
	//ft(i,1,top) printf("a[%d]=%d\n",i,a[i]);
	for(int i=1; i<=top; ){
		int j=i; while (j<top && a[j]==a[j+1]) j++;
		int x=j-max(a[i]-1,0), y=j-i+1;
		if (x<0 || y<0 || x<y){
			ans2=0;
			break;
		}
		ans2*=c[j-max(a[i]-1,0)][j-i+1];
		//printf("%d %d\n",j-max(a[i]-1,0),j-i+1);
		i=j+1;
	}
	//printf("ans2=%lld\n",ans2);
	printf("%lld\n",ans1-ans2-1);
}

int main(){
	init_c();
	int t; scanf("%d",&t);
	while (t--) solve();
	return 0;
}