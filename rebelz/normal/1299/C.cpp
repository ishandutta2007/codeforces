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

int n;
int f[1000005],lf[1000005],siz[1000005];
double a[1000005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),f[i]=lf[i]=i,siz[i]=1;
	a[n+1]=1<<30;
	for(int i=1;i<=n;i++){
		if(getf(i)!=i) continue;
		if(a[i]>a[getf(i+1)]){
			double tmp=(a[i]*siz[i]+a[f[i+1]]*siz[f[i+1]])/(siz[i]+siz[f[i+1]]);
			f[i]=f[i+1];
			siz[f[i+1]]+=siz[i];
			lf[f[i+1]]=lf[i];
			a[f[i+1]]=tmp;
			int fx=f[i];
			while(a[lf[fx]-1]>a[fx]){
				double tmp=(a[lf[fx]-1]*siz[lf[fx]-1]+a[fx]*siz[fx])/(siz[lf[fx]-1]+siz[fx]);
				f[lf[fx]-1]=fx;
				siz[fx]+=siz[lf[fx]-1];
				lf[fx]=lf[lf[fx]-1];
				a[fx]=tmp;
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%.10lf\n",a[getf(i)]);
	for(int i=1;i<=n;i++) 
	return 0;
}