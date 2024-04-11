#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,a[MN],b[MN];ll k;
char s[MN];
int main(){
	scanf("%d%lld%s",&n,&k,s+1);
	F(i,1,n)a[n+n+i]=a[n+i]=a[i]=s[i]=='W';
	F(i,1,n*3)b[i]=a[i];
	int tt=1;
	F(i,1,n)if(a[i]!=a[1])tt=0;
	if(tt)return printf("%s\n",s+1),0;
	tt=~n&1;
	F(i,1,n)if(a[i]!=(a[2]^(i&1)))tt=0;
	if(tt){if(k&1)F(i,1,n)s[i]=s[i]=='W'?'B':'W';printf("%s\n",s+1);return 0;}
	int lst=0,len=0;
	a[0]=-1;
	F(i,2,n*3){
		if(a[i]!=a[i-1])continue;
		if(lst&&a[i-2]!=a[i]){
			if((i^lst)&1){
				int x=(i-lst-1)/2;
				if(k>=x)F(j,lst+1,i-2)b[j]=a[i];
				else{
					if(k&1)F(j,lst+1,i-2)b[j]^=1;
					F(j,lst+1,lst+k)b[j]=a[lst];
					dF(j,i-2,i-k-1)b[j]=a[i];
				}
			}else{
				int x=(i-lst-2)/2;
				if(k>=x){
					F(j,lst+1,lst+x)b[j]=a[lst];
					F(j,lst+x+1,i-2)b[j]=a[i];
				}
				else{
					if(k&1)F(j,lst+1,i-2)b[j]^=1;
					F(j,lst+1,lst+k)b[j]=a[lst];
					dF(j,i-2,i-k-1)b[j]=a[i];
				}
			}
		}
		if(a[i-2]!=a[i])len=1;
		lst=i,++len;
	}
	F(i,n+1,n+n)printf("%c",b[i]?'W':'B');
	puts("");
	return 0;
}