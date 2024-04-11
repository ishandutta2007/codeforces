#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,ans[maxn],al;
char s[maxn];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(x,0,3){
		bool flag=true;
		int lst=-1;
		al=0;
		FOR(i,1,n+1){
			if(i==n+1) i=n+2;
			if(i>n || s[i]=='#'){
				if(lst!=i-1){
					int len=(i-x-1)-(lst+1)+1;
					if(len<=0){flag=false;break;}
					if(!x){
						if(len!=1){flag=false;break;}
					}
					else if(x==1){
						if(len%2!=1){flag=false;break;}
						FOR(j,1,(len-1)/2) ans[++al]=1;
					}
					else{
						if(len==2){flag=false;break;}
						FOR(j,1,(len-1)/2) ans[++al]=1;
						if(len%2==0) ans[al]=2;
					}
					ans[++al]=x+1;
				}
				else ans[al]++;
				lst=i;
			}
//			printf("x=%d\n",x);
		}
		if(flag){
			printf("%d\n",--al);
			FOR(i,1,al) printf("%d ",ans[i]);
			return 0;
		}
	}
	puts("-1");
}