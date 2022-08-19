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
int a[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		int sum=0;
		for(int i=1;i<=n;i++) sum^=a[i];
		if(sum){
			printf("NO\n");
			continue;
		}
		vector<int> ans(0);
		for(int i=1;i<=n;i++){
			if(!a[i]){
				if(i&1){
					for(int j=i-2;j>=1;j-=2) ans.pb(j);
					for(int j=1;j<i;j++) a[j]=0;
					break;
				}
				if(i==n) break;
				if(a[i+1]){
					for(int j=i-1;j>=1;j-=2) ans.pb(j);
					for(int j=1;j<=i+1;j++) a[j]=0;
					break;
				}
				ans.pb(i-1);
				a[i-1]=a[i]=a[i+1]=1;
			}
		}
		if(a[1]){
			printf("NO\n");
			continue;
		}
		for(int i=2;i<=n-2;i++){
			if(a[i]){
				int t=a[i]^a[i+1]^a[i+2];
				ans.pb(i);
				a[i]=a[i+1]=a[i+2]=t;
				if(t) ans.pb(i-1),a[i]=a[i+1]=0;
			}
		}
		if(a[n-1]&&a[n]) ans.pb(n-2);
		printf("YES\n");
		printf("%d\n",ans.size());
		for(auto r:ans) printf("%d ",r);
		printf("\n");
	}
	return 0;
}