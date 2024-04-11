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

int n,k,tot;
int prm[1000005],phi[1000005],fl[1000005];

void getprime(){
	fl[1]=phi[1]=1;
	for(int i=2;i<=n;i++){
		if(!fl[i]) prm[++tot]=i,phi[i]=i-1;
		for(int j=1;j<=tot&&i*prm[j]<=n;j++){
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
	n=readint(); k=readint();
	if(k==1) return printf("3\n"),0;
	getprime();
	sort(phi+1,phi+n+1);
	ll ans=0;
	for(int i=1;i<=k+2;i++) ans+=phi[i];
	printf("%lld\n",ans);
	return 0;
}