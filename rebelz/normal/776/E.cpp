#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,k,tot;
int prm[1000005],phi[1000005];
bool fl[1000005];

void getprime(int N){
	fl[1]=1,phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0){
				phi[i*prm[j]]=phi[i]*prm[j];
				break;
			}
			phi[i*prm[j]]=phi[i]*phi[prm[j]];
		}
	}
}

int main(){
	getprime(1000000);
	n=readint(); k=readint();
	k=(k+1)/2;
	for(int i=1;i<=k;i++){
		ll ans=1;
		for(int j=1;j<=tot;j++){
			if(n%prm[j]==0){
				ll all=1;
				while(n%prm[j]==0) n/=prm[j],all*=prm[j];
				ans*=all/prm[j]*(prm[j]-1);
			}
		}
		if(n>1) ans*=(n-1);
		if(ans==1) return printf("1\n"),0;
		else n=ans;
	}
	printf("%lld\n",n%1000000007);
	return 0;
}