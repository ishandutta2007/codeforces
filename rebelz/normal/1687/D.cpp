// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[1000005],lst[2000005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	n=unique(a+1,a+n+1)-a-1;
	a[n+1]=2000001;
	for(int i=1;i<=n;i++) for(int j=a[i];j<a[i+1];j++) lst[j]=i;
	for(ll i=1;i<=2000000;i++){
		if(a[1]>i*i+i) continue;
		ll l=i*i-a[1],r=i*i+i-a[1],bef=0;
		chkmax(l,0ll);
		for(ll j=i;;j++){
			ll val=j*j-i*i+j+a[1];
			int pl=val>2000000?n:lst[j*j-i*i+j+a[1]];
//			cout<<"test "<<i<<' '<<bef+1<<' '<<pl<<endl;
			ll L=j*j-a[bef+1];
			ll R=j*j+j-a[pl];
			chkmax(l,L),chkmin(r,R);
			if(l>r) break;
			if(pl==n) break;
			bef=pl;
		}
		if(l<=r){
			printf("%lld\n",l);
			return 0;
		}
	}
	assert(0);
	return 0;
}