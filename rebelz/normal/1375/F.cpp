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

ll a[5];

void solve(int x,int y,int z){
	printf("%lld\n",2*a[z]-a[y]);
	fflush(stdout);
	int tmp=readint();
	if(!tmp) return;
	assert(tmp!=z);
	if(tmp==x){
		printf("%lld\n",a[z]-a[y]);
		fflush(stdout);
		assert(!readint());
	}
	else{
		printf("%lld\n",a[z]);
		fflush(stdout);
		assert(!readint());
	}
}

int main(){
	a[1]=readint(); a[2]=readint(); a[3]=readint();
	printf("First\n");
	fflush(stdout);
	ll g=1000000000;
	printf("%lld\n",g);
	fflush(stdout);
	a[readint()]+=g;
	ll tmp=min(min(a[1],a[2]),a[3]);
	a[1]-=tmp,a[2]-=tmp,a[3]-=tmp;
	if(!a[1]){
		if(a[2]<a[3]) solve(1,2,3);
		else solve(1,3,2);
	}
	else if(!a[2]){
		if(a[1]<a[3]) solve(2,1,3);
		else solve(2,3,1);
	}
	else{
		if(a[1]<a[2]) solve(3,1,2);
		else solve(3,2,1);
	}
	return 0;
}