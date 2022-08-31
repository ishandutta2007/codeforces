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

int n;
ll a[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint()+a[i-1];
		if(a[n]!=0){
			puts("No");
			continue;
		}
		bool fl=0;
		for(int i=1;i<=n;i++) if(a[i]<0) fl=1;
		if(fl){
			puts("No");
			continue;
		}
		int pl=0;
		for(int i=1;i<=n;i++) if(a[i]>0) pl=i;
		for(int i=1;i<pl;i++) if(a[i]==0) fl=1;
		if(fl){
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
}