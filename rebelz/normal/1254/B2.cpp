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

ll n,sum,ans,res,tot,cnt;
ll a[1000005],b[1000005],prm[1000005],tmp[1000005];
bool fl[1000005];

void getprime(int N){
	fl[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=0;
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	getprime(1000000);
	n=readint();
	for(int i=1;i<=n;i++) tmp[i]=a[i]=readint(),sum+=a[i];
	for(int i=1;i<=tot;i++){
		if(sum%prm[i]==0){
			b[++cnt]=prm[i];
			while(sum%prm[i]==0) sum/=prm[i];
		}
	}
	if(sum>1) b[++cnt]=sum;
	res=1ll<<60;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=n;j++) a[j]=tmp[j];
		ll now=0,lst=1;
		ans=0;
		for(int j=1;j<=n;j++){
			now+=a[j]%b[i];
			if(now>=b[i]){
				ll tmp=0,pl=0;
				for(int k=lst;k<=j;k++){
					tmp+=a[k]%b[i];
					if(tmp>=(b[i]+1)/2){
						pl=k;
						break;
					}
				}
				for(int k=lst;k<j;k++) ans+=(a[k]%b[i])*abs(pl-k),a[k]=0;
				ans+=(a[j]%b[i]-(now-b[i]))*abs(pl-j);
				a[j]=now-b[i];
				lst=j;
				now=a[j];
			}
		}
		chkmin(res,ans);
	}
	if(res==(1ll<<60)) printf("-1\n");
	else printf("%lld\n",res);
	return 0;
}