#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=2e5+9;
struct node{
	int l,r,d;
}trap[N];
int a[N];
bool cmp2(int a,int b){
	return a>b;
}
bool cmp(node a,node b){
	if(a.l!=b.l)return a.l<b.l;
	if(a.d!=b.d)return a.d>b.d;
	return a.r>b.r;
}
int n,t,k;
bool check(int num){
	int val=a[num];
	int cost=n+1;
	int l=0,r=-1;
	rep(i,0,k){
		if(trap[i].d<=val)continue;
		if(trap[i].l>r){
			cost+=2*(r-l+1);
			l=trap[i].l;
			r=trap[i].r;
		}	
		else r=max(r,trap[i].r);
	}
	cost+=2*(r-l+1);
	return cost<=t;
}
int main(){
	int m;
	scanf("%d%d%d%d",&m,&n,&k,&t);
	rep(i,1,m+1)scanf("%d",&a[i]);
	sort(a+1,a+1+m,cmp2);
	rep(i,0,k){
		scanf("%d%d%d",&trap[i].l,&trap[i].r,&trap[i].d); 
	}
	sort(trap,trap+k,cmp);
	int l=1,r=m+1;
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid; 
	}
	cout<<l-1;
}