#include <bits/stdc++.h>
using namespace std;
struct node {
	int zhi,id;
}a[105];
bool cmp(node x,node y){
	return x.zhi>y.zhi;
}
vector<int> v1,v2;
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].zhi;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=0;i<m;i++){
		if(a[1].zhi-a[n].zhi==0){
			break;
		}
		ans++;
		v1.push_back(a[1].id);
		v2.push_back(a[n].id);
		a[1].zhi--;a[n].zhi++;
		sort(a+1,a+n+1,cmp);
	}
	cout<<a[1].zhi-a[n].zhi<<' '<<ans<<'\n';
	for(int i=0;i<ans;i++){
		cout<<v1[i]<<' '<<v2[i]<<'\n';
	}
	return 0;
}