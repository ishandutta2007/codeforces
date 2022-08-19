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

int n;
int a[100005],b[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		int now=1;
		while(now<n&&!a[now+1]) now++;
		int k=n;
		for(int j=1;j<k;j++){
			for(int i=now;i<n;i++) b[i]=a[i+1]-a[i];
			for(int i=now;i<n;i++) a[i]=b[i];
			sort(a+now,a+n);
			n--,now--;
			while(now<n&&!a[now+1]) now++;
			chkmax(now,1);
		}
		printf("%d\n",a[1]);
	}
	return 0;
}