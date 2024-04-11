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

int n,blo; ll ans=0;
char s[200005];
int a[200005],ps1[200005],ps2[200005],cnt[91000005];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=a[i-1]+(s[i]=='1');
	a[n+1]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) ps1[a[i]]=i;
		if(a[i]!=a[i+1]) ps2[a[i]]=i;
	}
	blo=sqrt(n);
	for(int i=1;i<=blo;i++){
		cnt[n]++;
		for(int j=1;j<=n;j++){
			ans+=cnt[i*a[j]+n-j];
			cnt[i*a[j]+n-j]++;
		}
		cnt[n]--;
		for(int j=1;j<=n;j++) cnt[i*a[j]+n-j]--;
	}
	for(int i=1;i<=n;i++){
		for(int j=a[i]-1;j>=max(0,a[i]-(n-1)/blo-1);j--){
			int rg=(i-ps1[j])/(a[i]-j);
			int lf=(i-ps2[j]-1)/(a[i]-j)+1;
			ans+=max(0,rg-max(lf,blo+1)+1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}