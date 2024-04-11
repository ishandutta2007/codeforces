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

int n;
ll a[5005],d[5005],f[5005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	memset(d,0x3f,sizeof(d));
	d[0]=0,d[1]=a[1];
	for(int i=2;i<=n;i++){
		ll now=0;
		for(int j=i;j>=1;j--){
			now+=a[j];
			if(now>=d[j-1]){
				d[i]=now;
				f[i]=f[j-1]+i-j;
				break;
			}
		}
	}
	printf("%lld\n",f[n]);
	return 0;
}