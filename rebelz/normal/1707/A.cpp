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

int n,m;
int a[100005],pos[100005];
bool res[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		if(m>=n){
			for(int i=1;i<=n;i++) putchar('1');
			putchar('\n');
		}
		else{
			int now=0;
			for(int i=1;i<=n;i++) res[i]=0;
			for(int i=n;i>=1;i--){
				if(a[i]<=now) res[i]=1;
				else if(now<m) res[i]=1,now++;
			}
			for(int i=1;i<=n;i++) putchar(res[i]+'0');
			putchar('\n');
		}
	}
	return 0;
}