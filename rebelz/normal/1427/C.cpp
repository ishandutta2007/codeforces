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

int r,n;
int t[100005],x[100005],y[100005],d[100005],f[100005];

int main(){
	r=readint(); n=readint();
	for(int i=1;i<=n;i++) t[i]=readint(),x[i]=readint(),y[i]=readint();
	x[0]=y[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		d[i]=-(1<<30);
		for(int j=i-1;j>=0;j--){
			if(t[i]-t[j]>=1000){
				chkmax(d[i],f[j]+1);
				break;
			}
			if(abs(x[j]-x[i])+abs(y[j]-y[i])<=t[i]-t[j]) chkmax(d[i],d[j]+1);
		}
		f[i]=max(f[i-1],d[i]);
		chkmax(ans,d[i]);
	}
	printf("%d\n",ans);
	return 0;
}