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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,tot;
int mu[10000005],cnt[10000005],p0[10000005],prm[1000005];
bool fl[10000005];

void getprime(){
	fl[1]=mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!fl[i]) prm[++tot]=i,p0[i]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*prm[j]<=n;j++){
			fl[i*prm[j]]=1,p0[i*prm[j]]=prm[j];
			if(i%prm[j]==0){
				mu[i*prm[j]]=0;
				break;
			}
			mu[i*prm[j]]=-mu[i];
		}
	}
}

int main(){
	n=readint();
	getprime();
	ll a1=0,ans=0;
	for(int i=1;i<=n;i++) a1+=mu[i]*(n/i)*(n/i);
	ans+=n*(n-1)/2-(a1-1)/2;
	a1-=n+n-1,a1/=2;
	ll tmp=n-1;
	for(int i=1;i<=tot;i++) if(prm[i]*2>n) a1-=tmp-1,tmp--;
	ll a2=0;
	for(int i=2;i<=n;i++) cnt[p0[i]]++;
	for(int i=2;i<=n;i++) cnt[i]+=cnt[i-1];
	for(int i=1;i<=tot;i++) if(1ll*prm[i]*prm[i]>n&&prm[i]*2<=n) a2+=cnt[prm[i]-1]-cnt[n/prm[i]];
	ans+=a2*3+(a1-a2)*2;
	printf("%lld\n",ans);
	return 0;
}