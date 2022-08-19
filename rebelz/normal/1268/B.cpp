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
int a[300005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	ll cnt0=0,cnt1=0;
	for(int i=1;i<=n;i++){
		if(i&1){
			cnt0+=a[i]/2;
			cnt1+=(a[i]+1)/2;
		}
		else{
			cnt1+=a[i]/2;
			cnt0+=(a[i]+1)/2;
		}
	}
	printf("%lld\n",min(cnt0,cnt1));
	return 0;
}