#include<bits/stdc++.h>
using namespace std;
struct node{
	int shu,i1,j1;
}a[5];
pair<int,int> s,x;
bool cmp(node x1,node x2){
	return x1.shu>x2.shu;
}
int main(){
	int n;
	scanf("%d%d%d",&n,&s.first,&s.second);
	a[0].i1=-1;
	a[1].j1=-1;
	a[2].i1=1;
	a[3].j1=1;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x.first,&x.second);
		if(x.first<s.first)a[0].shu++;
		if(x.second<s.second)a[1].shu++;
		if(x.first>s.first)a[2].shu++;
		if(x.second>s.second)a[3].shu++;
	} 
	sort(a,a+4,cmp);
	cout<<a[0].shu<<'\n';
	cout<<s.first+a[0].i1<<' '<<s.second+a[0].j1;
	return 0;
}