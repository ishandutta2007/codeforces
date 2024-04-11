#include<bits/stdc++.h>
using namespace std;
int fs[50]={
25,18,15,12,10,8,6,4,2,1
} ;
struct node{
	int f[51],jf;
	string s;
}a[1001];
bool cmp1(node x,node y){
	if(x.jf!=y.jf){
		return x.jf>y.jf;
	}
	for (int i=0;i<50;i++){
		if(x.f[i]!=y.f[i])return x.f[i]>y.f[i];
	}
}
bool cmp2(node x,node y){
	if(x.f[0]!=y.f[0])return x.f[0]>y.f[0];
	if(x.jf!=y.jf)return x.jf>y.jf;
	for(int i=1;i<50;i++){
		if(x.f[i]!=y.f[i])return x.f[i]>y.f[i];
	} 
}
int main(){
	int n,m;
	cin>>n;
	int i,q=0;string x;
	for(i=0;i<n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			bool p=1;cin>>x;
			for(int k=0;k<q;k++){
				if(a[k].s==x){
					a[k].f[j]++;a[k].jf+=fs[j];p=0;break;
				}
			}
			if(p){
				a[q].s=x;a[q].f[j]++;a[q].jf+=fs[j];q++;
			}
		}
	}
	sort(a,a+q,cmp1);
	cout<<a[0].s<<endl;
	sort(a,a+q,cmp2);
	cout<<a[0].s;
	return 0;
}