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
int a[5005];
ll d[5005][5005];

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		int pl=lower_bound(a+1,a+n+1,a[i]-5)-a;
		for(int j=0;j<=k;j++){
			d[i][j]=d[i-1][j];
			if(j) d[i][j]=max(d[i][j],d[pl-1][j-1]+i-pl+1);
			chkmax(ans,d[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}