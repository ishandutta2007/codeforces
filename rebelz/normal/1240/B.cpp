#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int a[300005],p[300005],mn[300005],mx[300005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) p[i]=a[i]=readint();
		sort(p+1,p+n+1); m=unique(p+1,p+n+1)-p-1;
		for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+m+1,a[i])-p;
		for(int i=1;i<=m;i++) mn[i]=1<<30,mx[i]=0;
		for(int i=1;i<=n;i++) chkmin(mn[a[i]],i),chkmax(mx[a[i]],i);
		mx[0]=1<<30;
		int cnt=1,res=0;
		for(int i=1;i<=m;i++){
			if(mx[i-1]<=mn[i]) cnt++;
			else cnt=1;
			chkmax(res,cnt);
		}
		printf("%d\n",m-res);
	}
	return 0;
}