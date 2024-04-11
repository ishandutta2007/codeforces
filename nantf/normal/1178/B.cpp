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
int n,pre[maxn],suf[maxn];
ll ans;
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,2,n){
		pre[i]=pre[i-1];
		if(s[i]=='v' && s[i-1]=='v') pre[i]++;
	} 
	ROF(i,n-1,1){
		suf[i]=suf[i+1];
		if(s[i]=='v' && s[i+1]=='v') suf[i]++;
	}
	FOR(i,1,n) if(s[i]=='o') ans+=1ll*pre[i-1]*suf[i+1];
	cout<<ans<<endl;
}