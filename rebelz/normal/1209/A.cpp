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
int a[105];
bool vis[105];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		int mina=1<<30;
		for(int j=1;j<=n;j++) if(!vis[j]) chkmin(mina,a[j]);
		if(mina==(1<<30)){
			printf("%d\n",i-1);
			return 0;
		}
		for(int j=1;j<=n;j++) if(a[j]%mina==0) vis[j]=1;
	}
	printf("%d\n",n);
	return 0;
}