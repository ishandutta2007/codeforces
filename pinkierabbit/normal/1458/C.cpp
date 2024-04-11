#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1005
#define MM 100005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,q,a[MN][MN],b[MN][MN];
char s[MM];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&q);
	F(i,1,n)F(j,1,n)scanf("%d",&a[i][j]);
	scanf("%s",s+1);
	int t1=1,t2=2,t3=3;
	int d1=0,d2=0,d3=0;
	F(i,1,q){
		if(s[i]=='R'){
			d2=(d2+1)%n;
		}
		if(s[i]=='L'){
			d2=(d2-1+n)%n;
		}
		if(s[i]=='D'){
			d1=(d1+1)%n;
		}
		if(s[i]=='U'){
			d1=(d1-1+n)%n;
		}
		if(s[i]=='I'){
			swap(t2,t3);
			swap(d2,d3);
		}
		if(s[i]=='C'){
			swap(t1,t3);
			swap(d1,d3);
		}
	}
	F(i,1,n)F(j,1,n){
		int x,y,z;
		x=(((t1==1?i:t1==2?j:a[i][j])+d1)%n-1+n)%n+1;
		y=(((t2==1?i:t2==2?j:a[i][j])+d2)%n-1+n)%n+1;
		z=(((t3==1?i:t3==2?j:a[i][j])+d3)%n-1+n)%n+1;
		b[x][y]=z;
	}
	F(i,1,n)F(j,1,n)printf("%d%c",b[i][j]," \n"[j==n]);
}	return 0;
}