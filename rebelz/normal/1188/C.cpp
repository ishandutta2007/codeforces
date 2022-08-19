#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
ll n,k,m;
ll a[1005],d[1005][1005],ans[100005],tmp[100005],s[1005][1005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	m=a[n]-a[1];
	ll pl;
	for(int i=1;i<=m/(k-1);i++){
		d[0][0]=s[0][0]=1;
		for(int j=1;j<=n;j++){
			pl=upper_bound(a+1,a+n+1,a[j]-i)-a-1;
			s[j][0]=1;
			for(int l=1;l<=k;l++) d[j][l]=s[pl][l-1],s[j][l]=mod(s[j-1][l]+d[j][l]);
			ans[i]=mod(ans[i]+d[j][k]);
		}
	}
	for(int i=1;i<=m/(k-1);i++) tmp[i]=mod(ans[i]-ans[i+1]+cys);
	ll res=0;
	for(int i=1;i<=m/(k-1);i++) res=mod(res+tmp[i]*i%cys);
	cout<<res<<endl;
	return 0;
}