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

int n,x;
ll a[200005];
map<ll,int> bk;

int main(){
	int T=readint();
	while(T--){
		n=readint(); x=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		bk.clear();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) bk[a[i]]++;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(bk[a[i]]){
				bk[a[i]]--;
				if(bk[a[i]*x]) bk[a[i]*x]--;
				else cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}