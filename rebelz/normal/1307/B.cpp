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

int n,x;
int a[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); x=readint();
		int maxa=0;
		for(int i=1;i<=n;i++) a[i]=readint(),chkmax(maxa,a[i]);
		int ans=(x-1)/maxa+1;
		if(ans==1){
			bool fl=0;
			for(int i=1;i<=n;i++) if(a[i]==x) fl=1;
			if(fl) printf("1\n");
			else printf("2\n");
		}
		else printf("%d\n",ans);
	}
	return 0;
}