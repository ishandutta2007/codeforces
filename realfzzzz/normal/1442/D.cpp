#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=3e3+5;
int n,k,t[maxn];
vector<int> a[maxn];
typedef long long ll;
ll s[maxn],f[maxn],ans=0;
void solve(int l,int r){
	if(l==r){
		ans=max(ans,f[k]);
		ll s=0;
		for(int i=1;i<=min(t[r],k);i++){
			s+=a[r][i];
			ans=max(ans,s+f[k-i]);
		}
		return;
	}
	vector<ll> tmp(k+1);
	for(int i=0;i<=k;i++) tmp[i]=f[i];
	int mid=l+(r-l)/2;
	for(int i=l;i<=mid;i++)
		for(int j=k;j>=t[i];j--)
			f[j]=max(f[j],f[j-t[i]]+s[i]);
	solve(mid+1,r);
	for(int i=0;i<=k;i++) f[i]=tmp[i];
	for(int i=mid+1;i<=r;i++)
		for(int j=k;j>=t[i];j--)
			f[j]=max(f[j],f[j-t[i]]+s[i]);
	solve(l,mid);
	for(int i=0;i<=k;i++) f[i]=tmp[i];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	k=readint();
	for(int i=1;i<=n;i++){
		t[i]=readint();
		a[i].resize(t[i]+1);
		for(int j=1;j<=t[i];j++)
			s[i]+=(a[i][j]=readint());
	}
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}