#include<bits/stdc++.h>

#define y1 dmytxdy
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
int a[100005],b[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) b[i]=readint();
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int now=n/4,sa=0,sb=0;
		for(int i=now+1;i<=n;i++) sa+=a[i],sb+=b[i];
		int pl=now;
		for(int i=n;;i++){
			if(i/4!=now) now++,sa-=a[now];
			else if(i>n&&pl) sb+=b[pl],pl--;
			if(i>n) sa+=100;
			if(sa>=sb){
				printf("%d\n",i-n);
				break;
			}
		}
	}
	return 0;
}