#include <bits/stdc++.h>
using namespace std;
struct node{
	int zhi,id,h;
}a[200005];
bool cmp(node x,node y){
	return x.zhi<y.zhi;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[2*i-1].zhi,a[2*i-1].id=i;
		cin>>a[2*i].zhi,a[2*i].id=i;a[2*i].h=1;
	}
	int ans[2][100005];
	memset(ans,0,sizeof(ans));
	for(int i=0;i<2;i++){
		for(int j=1;j<=n/2;j++)ans[i][j]=1;
	}
	sort(a+1,a+n*2+1,cmp);
	for(int i=1;i<=n;i++){
		ans[a[i].h][a[i].id]=1;
	}
	for(int i=0;i<2;i++){
		for(int j=1;j<=n;j++)cout<<ans[i][j];
		cout<<'\n';
	}
	return 0;
}