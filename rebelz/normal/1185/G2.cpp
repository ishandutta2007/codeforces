#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,T;
int f[2505][55][55],g[2505][55],d[55][55][55],lst[55][55][55][5],fac[55];
vector<int> a[5];

int mod(int x){return x>=cys?x-cys:x;}

int main(){
	n=readint(); T=readint();
	int x,y;
	for(int i=1;i<=n;i++){
		x=readint(); y=readint();
		a[y-1].push_back(x);
	}
	f[0][0][0]=1;
	for(int i=0;i<a[0].size();i++)
		for(int j=T-a[0][i];j>=0;j--)
			for(int k=0;k<=i;k++)
				f[j+a[0][i]][k+1][0]=mod(f[j+a[0][i]][k+1][0]+f[j][k][0]);
	for(int i=0;i<a[1].size();i++)
		for(int j=T-a[1][i];j>=0;j--)
			for(int k=0;k<=i;k++)
				for(int l=0;l<=a[0].size();l++)
					f[j+a[1][i]][l][k+1]=mod(f[j+a[1][i]][l][k+1]+f[j][l][k]);
	g[0][0]=1;
	for(int i=0;i<a[2].size();i++)
		for(int j=T-a[2][i];j>=0;j--)
			for(int k=0;k<=i;k++)
				g[j+a[2][i]][k+1]=mod(g[j+a[2][i]][k+1]+g[j][k]);
	for(int i=0;i<=T;i++)
		for(int j=0;j<=a[0].size();j++)
			for(int k=0;k<=a[1].size();k++)
				for(int l=0;l<=a[2].size();l++)
					d[j][k][l]=mod(d[j][k][l]+1ll*f[i][j][k]*g[T-i][l]%cys);
	lst[1][0][0][0]=1,lst[0][1][0][1]=1,lst[0][0][1][2]=1;
	for(int i=0;i<=a[0].size();i++){
		for(int j=0;j<=a[1].size();j++){
			for(int k=0;k<=a[2].size();k++){
				if(i<a[0].size()) lst[i+1][j][k][0]=mod(lst[i+1][j][k][0]+mod(lst[i][j][k][1]+lst[i][j][k][2]));
				if(j<a[1].size()) lst[i][j+1][k][1]=mod(lst[i][j+1][k][1]+mod(lst[i][j][k][0]+lst[i][j][k][2]));
				if(k<a[2].size()) lst[i][j][k+1][2]=mod(lst[i][j][k+1][2]+mod(lst[i][j][k][0]+lst[i][j][k][1]));
			}
		}
	}
	ll ans=0;
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%cys;
	for(int i=0;i<=a[0].size();i++)
		for(int j=0;j<=a[1].size();j++)
			for(int k=0;k<=a[2].size();k++)
				ans=mod(ans+1ll*mod(mod(lst[i][j][k][0]+lst[i][j][k][1])+lst[i][j][k][2])*d[i][j][k]%cys*fac[i]%cys*fac[j]%cys*fac[k]%cys);
	cout<<ans<<endl;
	return 0;
}