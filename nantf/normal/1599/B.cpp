#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
ll n,a,b;
bool ta,tb,flag;
char s[maxn];
void solve(){
	n=read();a=read();b=read();
	scanf("%s",s);ta=s[0]=='r';
	scanf("%s",s);tb=s[0]=='r';
	flag=false;
	while(true){
		if(!a) ta=1;
		if(a==n-1) ta=0;
		if(!b) tb=1;
		if(b==n-1) tb=0;
		if(a==b) break;
		if(ta) flag^=1,a=n-1-a,b=n-1-b,ta^=1,tb^=1;
		if(tb){
			if(a<b){
				ll c=min(a,n-1-b);
				a-=c;b+=c;
			}
			else{
				if((a^b)&1){
					a=b=(a+b)/2;
					swap(ta,tb);
				}
				else a=b=(a+b)/2;
			}
		}
		else{
			if(a<b){
				b-=a;a=0;
			}
			else{
				if(a==b+1) a=b;
				else a-=b,b=0;
			}
		}
	}
	if(flag) a=n-1-a,b=n-1-b,ta^=1,tb^=1;
	printf("%lld\n",tb?0:n-1);
}
int main(){
	int T=read();
	while(T--) solve();
}