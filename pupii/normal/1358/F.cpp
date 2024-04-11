#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
ll A[200010],B[200010];
int n;
char op[10000010];
void solve(){
	int sum=0,P=0;
	while(1){
		bool incr=1,decr=1,same=1,rsame=1;
		for(int i=1;i<=n;++i)same&=A[i]==B[i];
		for(int i=1;i<=n;++i)rsame&=A[i]==B[n-i+1];
		if(same)break;
		if(rsame){op[++sum]='R';break;}
		for(int i=1;i<n;++i)incr&=B[i]<=B[i+1],decr&=B[i]>=B[i+1];
		if(!incr&&!decr)puts("IMPOSSIBLE"),exit(0);
		++sum;
		if(incr){
			op[sum]='P';++P;
			for(int i=n;i;--i)B[i]-=B[i-1];
		}else op[sum]='R',std::reverse(B+1,B+n+1);
	}
	printf("%s\n%d\n",P>200000?"BIG":"SMALL",P>200000?P:sum);
	if(P<=200000)while(sum)putchar(op[sum--]);
}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<=n;++i)A[i]=gi();
	for(int i=1;i<=n;++i)B[i]=gi();
	if(n==1){
		if(A[1]==B[1])puts("SMALL\n0\n");
		else puts("IMPOSSIBLE");
		exit(0);
	}
	if(n>2)solve();
	else{
		ll a=B[1],b=B[2],sum=0;
		while(a&&b){
			if(a==A[1]&&b==A[2])break;
			if(b==A[1]&&a==A[2]){std::swap(a,b);break;}
			if(a>b)std::swap(a,b);
			else{
				if(a==A[1]&&A[2]<=b&&(b-A[2])%a==0)sum+=(b-A[2])/a,b=A[2];
				else if(a==A[2]&&A[1]<=b&&(b-A[1])%a==0)sum+=(b-A[1])/a,b=A[1];
				else sum+=b/a,b%=a;
			}
		}
		if(a!=A[1]||b!=A[2])puts("IMPOSSIBLE");
		else if(sum<=200000)solve();
		else printf("BIG\n%lld\n",sum);
	}
	return 0;
}