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

int n,q,tot;
bool fl[1000005];
int prm[1000005],d0[1000005],a[300005],b[300005];

void getprime(int m){
	fl[1]=1;
	for(int i=2;i<=m;i++){
		if(!fl[i]) prm[++tot]=i,d0[i]=i;
		for(int j=1;j<=tot&&i*prm[j]<=m;j++){
			fl[i*prm[j]]=1,d0[i*prm[j]]=prm[j];
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	int T=readint();
	getprime(1000000);
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++){
			b[i]=1;
			while(a[i]>1){
				int t=d0[a[i]],num=0;
				while(a[i]%t==0) a[i]/=t,num^=1;
				if(num) b[i]*=t;
			}
		}
		sort(b+1,b+n+1);
		int num=1,ans0=0,ans1=0,sum=0;
		b[n+1]=-1;
		for(int i=2;i<=n+1;i++){
			if(b[i]==b[i-1]) num++;
			else{
				if(b[i-1]==1&&num%2!=0) sum+=num;
				chkmax(ans0,num);
				if(num%2==0) sum+=num;
				else chkmax(ans1,num);
				num=1;
			}
		}
		chkmax(ans1,sum);
		q=readint();
		while(q--){
			ll tmp=readint();
			if(!tmp) printf("%d\n",ans0);
			else printf("%d\n",ans1);
		}
	}
	return 0;
}