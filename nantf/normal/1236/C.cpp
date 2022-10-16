#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,ans[333][333],cnt1,cnt2;
int main(){
	n=read();
	if(n%2==0){
		cnt1=n*n/2;cnt2=n*n/2+1;
		FOR(i,1,n){
			FOR(j,1,n/2) printf("%d ",cnt1--);
			FOR(j,1,n/2) printf("%d ",cnt2++);
			puts("");
		}
	}
	else{
		cnt1=n*(n-1);cnt2=1;
		FOR(i,1,n) FOR(j,1,(n-1)/2) ans[i][j]=cnt1--;
		FOR(i,1,n) FOR(j,(n-1)/2+1,n-1) ans[i][j]=cnt2++;
		FOR(i,1,n) ans[i][n]=n*n+1-i;
		FOR(i,1,n){
			FOR(j,1,n) printf("%d ",ans[i][j]);
			puts("");
		}
	}
}