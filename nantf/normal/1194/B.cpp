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
int q,n,m,cmx,cnt1[maxn],cnt2[maxn];
string s[maxn];
int main(){
	q=read();
	while(q--){
		n=read();m=read();
		cmx=0;
		FOR(i,1,n){
			cin>>s[i];
			FOR(j,1,m) if(s[i][j-1]=='*') cnt1[i]++,cnt2[j]++;
		}
		int ans=1e9;
		FOR(i,1,n) FOR(j,1,m) ans=min(ans,n+m-cnt1[i]-cnt2[j]-(s[i][j-1]=='.'));
		printf("%d\n",ans);
		FOR(i,1,n) cnt1[i]=0;
		FOR(i,1,m) cnt2[i]=0;
	}
}