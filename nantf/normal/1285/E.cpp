#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444;
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
struct seg{
	int l,r;
	bool operator<(const seg &s)const{return l<s.l;}
}s[maxn];
int t,n,mx[2][maxn],pre[2][maxn];
int main(){
	t=read();
	while(t--){
		n=read();
		FOR(i,1,n){
			s[i].l=read();s[i].r=read();
		}
		sort(s+1,s+n+1);
		FOR(i,0,n) mx[0][i]=mx[1][i]=-2e9;
		FOR(i,1,n){
			mx[0][i]=mx[0][i-1];
			mx[1][i]=mx[1][i-1];
			if(s[i].r>mx[0][i]) mx[1][i]=mx[0][i],mx[0][i]=s[i].r;
			else mx[1][i]=max(mx[1][i],s[i].r);
			pre[0][i]=pre[0][i-1]+(s[i].l>mx[0][i-1]);
			pre[1][i]=pre[1][i-1]+(s[i].l>mx[1][i-1]);
		}
		int ans=0;
		FOR(i,1,n){
			int p1=lower_bound(mx[0]+i,mx[0]+n+1,s[i].r)-mx[0];
			int p2=lower_bound(mx[0]+i,mx[0]+n+1,s[i].r+1)-mx[0];
			if(mx[0][p1]!=s[i].r) ans=max(ans,pre[0][n]);
			else{
				p2--;
				assert(mx[0][p2]==s[i].r);
				bool in=i>=p1+1 && i<=p2+1 && s[i].l>mx[1][i-1] || (i<p1+1 || i>p2+1) && s[i].l>mx[0][i-1];
				ans=max(ans,pre[0][p1]+pre[1][min(n,p2+1)]-pre[1][p1]+pre[0][n]-pre[0][min(n,p2+1)]-in);
			}
		}
		printf("%d\n",ans);
	}
}