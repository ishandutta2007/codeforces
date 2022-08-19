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

ll n,tot;
ll prm[1000005];
bool fl[1000005];

void getprime(ll N){
	fl[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	n=readint();
	getprime(1000000);
	ll cnt=0,x=1,t=n;
	for(int i=1;i<=tot;i++){
		if(t%prm[i]==0){
			cnt++;
			if(cnt==2) return printf("1\n"),0;
			else x=prm[i];
			while(t%prm[i]==0) t/=prm[i];
		}
	}
	if(t>1){
		cnt++;
		if(cnt==2) return printf("1\n"),0;
		else x=t;
	}
	printf("%lld\n",x);
	return 0;
}