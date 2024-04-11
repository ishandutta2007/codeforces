#include<bits/stdc++.h>

#define y1 dmytxdy
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
int dep[100005],a[100005];

int main(){
	n=readint();
	dep[1]=a[1]=1;
	int x;
	for(int i=2;i<=n;i++){
		x=readint();
		dep[i]=dep[x]+1;
		a[dep[i]]^=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}