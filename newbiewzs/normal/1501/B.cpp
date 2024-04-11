#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
#include<cmath>
//#define int long long
using namespace std;
int T,n;
const int N=2e5+55;
int a[N];
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
int bj[N*4];
void build(int u,int l,int r){
	if(l==r){
		bj[u]=0;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	bj[u]=0;
}
void add(int u,int l,int r,int L,int R){
	if(L<=l and R>=r){
		bj[u]=1;
		return ;
	}
	if(L<=mid)add(ls,l,mid,L,R);
	if(R>mid)add(rs,mid+1,r,L,R);
	return ;
}
void query(int u,int l,int r){
	if(bj[u]){
		for(int k=l;k<=r;k++){
			printf("1 ");
		}
		return ;
	}
	bj[u]=0;
	if(l==r){
		printf("%d ",bj[u]);
		return ;
	}
	query(ls,l,mid);
	query(rs,mid+1,r);
}
int main(){
	cin>>T;
	while(T--){
		scanf("%d",&n);
		build(1,1,n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(a[i])add(1,1,n,max(1,i-a[i]+1),i);
		}
		query(1,1,n);
		puts("");
	}
	return 0;
	// using long long?
	// d somet
	// think t d a
}