#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
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
int n,a[maxn],l[maxn],r[maxn],cnt;
ll w[maxn];
double ans[maxn];
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	cnt=1;
	l[1]=r[1]=n;w[1]=a[n];
	l[0]=n+1;
	ROF(i,n-1,1){
		int tot=1;
		ll s=a[i];
		while(cnt && w[cnt]*tot<=s*(r[cnt]-l[cnt]+1)){
			s+=w[cnt];
			tot+=r[cnt]-l[cnt]+1;
			cnt--;
		}
		cnt++;
		r[cnt]=l[cnt-1]-1;
		l[cnt]=i;
		w[cnt]=s;
	}
	FOR(i,1,cnt) FOR(j,l[i],r[i]) ans[j]=1.0*w[i]/(r[i]-l[i]+1);
	FOR(i,1,n) printf("%.10lf\n",ans[i]);
}
// shit round