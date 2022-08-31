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

int n,x;
int a[105];

int main(){
	int T=readint();
	while(T--){
		n=readint(); x=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		sort(a+1,a+n+1);
		reverse(a+1,a+n+1);
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		if(sum==x){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		int now=0,fl=0;
		for(int i=2;i<=n;i++){
			if(!fl&&now>x-a[1]) printf("%d ",a[1]),fl=1;
			now+=a[i],printf("%d ",a[i]);
		}
		if(!fl) printf("%d ",a[1]);
		printf("\n");
	}
	return 0;
}