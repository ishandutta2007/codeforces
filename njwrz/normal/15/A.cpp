#include<bits/stdc++.h>
using namespace std;
struct node{
	double a,b;
}f[1001];
bool cmp(node x,node y){
	return x.a<y.a;
}
int main(){
	double m,t;
	int i,n,s=2;
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>f[i].a>>f[i].b;
	sort(f,f+n,cmp);
	for(i=n-1;i>=0;i--){
		t=f[i+1].a-f[i+1].b/2-f[i].a-f[i].b/2;
		if(t>m){
			s+=2;
		}else if(t==m){
			s+=1;
		}
	}
	cout<<s;
	return 0;
}