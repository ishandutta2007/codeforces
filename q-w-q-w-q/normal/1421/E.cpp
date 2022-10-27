#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int n,a[200001];
ll f[200001][3][2],g[200001][3][2],x,y;
inline void ck(ll &a,ll b,ll c){
	if(b!=-(1ll<<60)&&(a==-(1ll<<60)||a<b+c)) a=b+c;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	if(n==1){
		cout<<a[1];
		return 0;
	}
	for(int i=1;i<=n;i++)
	for(int j=0;j<3;j++)
	for(int k=0;k<2;k++)
	f[i][j][k]=g[i][j][k]=-(1ll<<60);
	f[1][1][0]=a[1],g[1][0][0]=-a[1];
	for(int i=2;i<=n;i++){
		ck(f[i][0][0],g[i-1][2][0],a[i]);
		ck(f[i][1][0],g[i-1][0][0],a[i]);
		ck(f[i][2][0],g[i-1][1][0],a[i]);
		ck(g[i][0][0],f[i-1][0][0],-a[i]);
		ck(g[i][1][0],f[i-1][1][0],-a[i]);
		ck(g[i][2][0],f[i-1][2][0],-a[i]);
		ck(f[i][0][1],f[i-1][2][0],a[i]);
		ck(f[i][0][1],f[i-1][2][1],a[i]);
		ck(f[i][0][1],g[i-1][2][1],a[i]);
		ck(f[i][1][1],f[i-1][0][0],a[i]);
		ck(f[i][1][1],f[i-1][0][1],a[i]);
		ck(f[i][1][1],g[i-1][0][1],a[i]);
		ck(f[i][2][1],f[i-1][1][0],a[i]);
		ck(f[i][2][1],f[i-1][1][1],a[i]);
		ck(f[i][2][1],g[i-1][1][1],a[i]);
		ck(g[i][0][1],g[i-1][0][0],-a[i]);
		ck(g[i][0][1],g[i-1][0][1],-a[i]);
		ck(g[i][0][1],f[i-1][0][1],-a[i]);
		ck(g[i][1][1],g[i-1][1][0],-a[i]);
		ck(g[i][1][1],g[i-1][1][1],-a[i]);
		ck(g[i][1][1],f[i-1][1][1],-a[i]);
		ck(g[i][2][1],g[i-1][2][0],-a[i]);
		ck(g[i][2][1],g[i-1][2][1],-a[i]);
		ck(g[i][2][1],f[i-1][2][1],-a[i]);
	}
	x=f[n][2-n%3][1],y=g[n][2-n%3][1];
	if(x==-(1ll<<60)) cout<<y;
	else if(y==-(1ll<<60)) cout<<x;
	else cout<<max(x,y);
}