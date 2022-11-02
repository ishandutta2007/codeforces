#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
#define mid ((l+r)>>1)
const int N=2e5+55;
int n,m,a[N],b[N];
struct node{
	int id,val;
}st[N];int top;
int cmp(node x,node y){
	return x.val>y.val;
}
int l,r,jl;
int check(int x){
	ll cal=0;
	for(int i=1;i<=n;i++){
		int l=0,r=a[i]-1,tmp=0;
		while(l<=r){
			if(-3*mid*mid+3*mid+a[i]-1>=x)tmp=mid,l=mid+1;
			else r=mid-1;
		}
		cal+=tmp+1;
	}
	return cal;
}
int solve(int x){
	ll cal=0;
	for(int i=1;i<=n;i++){
		int l=0,r=a[i]-1,tmp=0;
		if(i==4){
			new char;
		}
		while(l<=r){
			if(-3*mid*mid+3*mid+a[i]-1>=x)tmp=mid,l=mid+1;
			else r=mid-1;
		}
		b[i]=tmp+1;cal+=tmp+1;
	}
	return cal;
}
signed main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	l=-4e18,r=4e18;
	while(l<=r){
		if(check(mid)<=m)jl=mid,r=mid-1;
		else l=mid+1;
	}
	int tmp=solve(jl);
	if(tmp<m){
		for(int i=1;i<=n;i++){
			if(b[i]<a[i])
			{
				st[++top]={i,-3*b[i]*b[i]+3*b[i]+a[i]-1};
			}
		}
		sort(st+1,st+top+1,cmp);
		for(int i=1;i<=m-tmp;i++){
			if(i!=1 and st[i].val!=st[i-1].val)cout<<"qwq";
			b[st[i].id]++;
		}
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
	return 0;
}