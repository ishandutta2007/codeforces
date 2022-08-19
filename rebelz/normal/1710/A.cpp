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

int n,m,k;
int a[100005];

bool check(){
	ll sum=0;
	int fl=0;
	for(int i=1;i<=k;i++){
		ll num=a[i]/n;
		if(num>=2) sum+=num;
		if(num>2) fl=1;
	}
	if(sum<m) return 0;
	if(sum==m) return 1;
	if(fl) return 1;
	if(m&1) return 0;
	return 1;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint(); k=readint();
		for(int i=1;i<=k;i++) a[i]=readint();
		if(check()) puts("Yes");
		else{
			swap(n,m);
			if(check()) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}