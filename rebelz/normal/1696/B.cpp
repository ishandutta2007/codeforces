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
int a[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		bool fl=0;
		for(int i=1;i<=n;i++) if(a[i]) fl=1;
		if(!fl){
			puts("0");
			continue;
		}
		int l=n+1,r=0;
		for(int i=1;i<=n;i++) if(a[i]) chkmin(l,i),chkmax(r,i);
		fl=0;
		for(int i=l;i<=r;i++) if(!a[i]) fl=1;
		if(!fl) puts("1");
		else puts("2");
	}
	return 0;
}