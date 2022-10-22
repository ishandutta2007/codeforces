#include<bits/stdc++.h>
using namespace std;
struct node {
	int fy,g;
}p[100001];
struct node1{
	int ll,d;
}a[100001];
bool cmp(node x,node y){
	return x.fy<y.fy;
}
bool cmp1(node1 x,node1 y){
	return x.ll<y.ll;
}
int qz[100001];
int main(){
	int n,i,m,ans[100001];
	cin>>n>>m;
	for(i=0;i<n;i++){
		int yy;
		cin>>yy;
		a[i].ll=yy;
		a[i].d=i;
	}
	for(i=0;i<m;i++)cin>>p[i].fy>>p[i].g;
	
	sort(a,a+n,cmp1);
	sort(p,p+m,cmp);qz[0]=p[0].g;for(i=1;i<m;i++)qz[i]=qz[i-1]+p[i].g;
	int l=0;
	for(i=0;i<n;i++){
		while(p[l].fy<=a[i].ll&&l<m)l++;
		ans[a[i].d]=qz[l-1];
	}
	for(i=0;i<n;i++)cout<<ans[i]<<" ";
	return 0;
}