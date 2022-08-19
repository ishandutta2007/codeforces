// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int l,r;

int getans(int i,int x){
	int t=x/(1<<(i+1))*(1<<i);
	x%=(1<<(i+1));
	if(x>=(1<<i)) t+=x-(1<<i)+1;
	return t;
}

int main(){
	int T=readint();
	while(T--){
		l=readint(); r=readint();
		int ans=r-l+1;
		for(int i=0;i<20;i++) chkmin(ans,r-l+1-getans(i,r)+getans(i,l-1));
		printf("%d\n",ans);
	}
	return 0;
}