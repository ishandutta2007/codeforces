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
int n,m,f[N],a[N],b[N];
int bit[N];
struct node{
	int id,val;
}s[N];
int cmp(node x,node y){
	if(x.val!=y.val)return x.val<y.val;
	else return x.id<y.id;
}
int cmp1(node x,node y){
	return x.id<y.id;
}
void add(int x,int k){
	for(;x<=n*m;x+=x&(-x))bit[x]+=k;
}
int query(int x){
	int summ=0;
	for(;x;x-=(x&(-x)))summ+=bit[x];
	return summ;
}
void solve(){
	n=read();m=read();
	for(int i=1;i<=n*m;i++)a[i]=f[i]=read(),s[i]={i,a[i]};
	sort(f+1,f+n*m+1);
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)a[i]=lower_bound(f+1,f+n*m+1,a[i])-f;
	sort(a+1,a+n*m+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		sort(s+(i-1)*m+1,s+i*m+1,cmp1);
		for(int k=1;k<=m;k++)b[k]=s[(i-1)*m+k].val;
		for(int k=1;k<=m;k++)b[k]=lower_bound(f+1,f+n*m+1,b[k])-f;
		for(int k=1;k<=m;k++){
			ans=ans+query(b[k]-1);
			add(b[k],1);
		}
		for(int k=1;k<=m;k++){
			add(b[k],-1);
		}
	}
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