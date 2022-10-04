#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
#define ll long long
#define ld double
using namespace std;
typedef pair<int,int> pii;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
const int INF=0x3f3f3f3f;

int n;ll C1,C2;
ll a[300005],b[300005];int p[300005];
int ok1[300005],ok2[300005];
int r1[300005],r2[300005];
bool cmp(int p1,int p2){return b[p1]<b[p2];}

int main(){
	scanf("%d%I64d%I64d",&n,&C1,&C2);
	F(i,1,n) scanf("%I64d",b+i), p[i]=i;
	sort(p+1,p+n+1,cmp);
	F(i,1,n) a[i]=b[p[i]];
	int nums;
	dF(i,n,1){
		nums=(C1-1)/a[i]+1;
		if(i+nums<=n){
			if(ok2[i+nums]){
				printf("Yes\n%d %d\n",nums,r2[ok2[i+nums]]-ok2[i+nums]+1);
				F(j,i,i+nums-1) printf("%d ",p[j]); puts("");
				F(j,ok2[i+nums],r2[ok2[i+nums]]) printf("%d ",p[j]);
				return 0;
			}
		}
		if(i+nums-1<=n) ok1[i]=i; r1[i]=i+nums-1;
		if(ok1[i+1]) ok1[i]=ok1[i+1];
		nums=(C2-1)/a[i]+1;
		if(i+nums<=n){
			if(ok1[i+nums]){
				printf("Yes\n%d %d\n",r1[ok1[i+nums]]-ok1[i+nums]+1,nums);
				F(j,ok1[i+nums],r1[ok1[i+nums]]) printf("%d ",p[j]); puts("");
				F(j,i,i+nums-1) printf("%d ",p[j]);
				return 0;
			}
		}
		if(i+nums-1<=n) ok2[i]=i; r2[i]=i+nums-1;
		if(ok2[i+1]) ok2[i]=ok2[i+1];
	} puts("No");
	return 0;
}