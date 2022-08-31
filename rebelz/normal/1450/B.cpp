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

int n,k;
int x[105],y[105];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint();
		bool fl=0;
		for(int i=1;i<=n;i++){
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(abs(x[i]-x[j])+abs(y[i]-y[j])<=k) cnt++;
			}
			if(cnt==n-1) fl=1;
		}
		if(fl) printf("1\n");
		else printf("-1\n");
	}
	return 0;
}