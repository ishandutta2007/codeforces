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
int a[10005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i];
		if(sum%n!=0){
			printf("-1\n");
			continue;
		}
		sum/=n;
		printf("%d\n",3*(n-1));
		for(int i=2;i<=n;i++){
			int tmp=(i-a[i]%i)%i;
			printf("%d %d %d\n",1,i,tmp);
			a[i]+=tmp,a[1]-=tmp;
			assert(a[1]>=0);
			assert(a[i]%i==0);
			printf("%d %d %d\n",i,1,a[i]/i);
			a[1]+=a[i],a[i]=0;
		}
		for(int i=2;i<=n;i++) printf("%d %d %d\n",1,i,sum);
	}
	return 0;
}