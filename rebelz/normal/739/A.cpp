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

int n,m;

int main(){
	n=readint(); m=readint();
	int ans=1<<30;
	for(int i=1;i<=m;i++){
		int l=readint(),r=readint();
		chkmin(ans,r-l+1);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",i%ans);
	printf("\n");
	return 0;
}