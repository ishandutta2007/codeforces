#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
	int id,x,r,ans;
}a[10005];
bool cmp1(node x1,node x2){
	return x1.x<x2.x;
}
bool cmp2(node x1,node x2){
	return x1.id<x2.id;
}
bool jc(int x1,int x2,int p){
	if(p<1||p>n)return 0;
	if(a[p].ans!=-1)return 0;
	if(abs(a[p].x-x1)*abs(a[p].x-x1)+x2*x2<=
		a[p].r*a[p].r)return 1;
	return 0;
}
int ef(int mb){
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[mid].x>mb)r=mid-1;else l=mid+1;
	}
	return l;
}
int main(){
	int x1,x2,anss=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].r;
		a[i].id=i;a[i].ans=-1;
	}
	sort(a+1,a+n+1,cmp1);
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>x1>>x2;
		int t=ef(x1);
		for(int j=-1;j<2;j++){
			if(jc(x1,abs(x2),t+j))anss++,a[t+j].ans=i+1;
		}
	}
	sort(a+1,a+n+1,cmp2);
	cout<<anss<<'\n';
	for(int i=1;i<=n;i++)cout<<a[i].ans<<' ';
	return 0;
}