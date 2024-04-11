#include <bits/stdc++.h>
using namespace std;
struct node{
	long long zhi;
	int id;
}a[400005];
bool cmp(node x,node y){
	return x.zhi<y.zhi||(x.zhi==y.zhi&&x.id<y.id);
}
long long f[200005];
int main(){
	long long n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i*2].zhi>>a[i*2+1].zhi;a[i*2].id=0;a[i*2+1].id=1;
	}
	sort(a,a+n*2,cmp);
	long long l=0,last=0,lasti=0;
	for(int i=0;i<n*2;i++){
		f[l]+=a[i].zhi-last+1;
		last=a[i].zhi;
		if(lasti)f[l]--;
		if(!a[i].id)f[l]--;
		if(a[i].id)l--;else l++;
		lasti=a[i].id;
	}
	for(int i=1;i<=n;i++)cout<<f[i]<<' ';
	return 0;
}