#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<cmath> 
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
using namespace std;
int read(){
	char c=getchar();int x=1;int s=0;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}
const int N=1e5+5;
int n,m,f[N],a[N];
int bit[N];
void add(int x,int k){
	for(;x<=n;x+=x&(-x))bit[x]+=k;
}
int query(int x){
	int summ=0;
	for(;x;x-=(x&(-x)))summ+=bit[x];
	return summ;
}
void solve(){
	n=read();m=read();
	swap(n,m);
	for(int i=1;i<=n;i++)a[i]=f[i]=read();
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(f+1,f+n+1,a[i])-f;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=ans+=query(a[i]-1);
		add(a[i],1);
	}
	for(int i=1;i<=n;i++)add(a[i],-1);
	cout<<ans<<'\n';
}
signed main(){
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}