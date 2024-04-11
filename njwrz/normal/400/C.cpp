#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,p,x,y,z,p1,p2;
	cin>>n>>m>>x>>y>>z>>p;
	int tn,tm,t;
	x%=4;
	y%=2;
	z%=4;
	for(int i=0;i<p;i++){
		cin>>p1>>p2;
		tn=n;
		tm=m;
		for(int j=0;j<x;j++){
			t=p2;
			p2=tn-p1+1;
			p1=t;
			swap(tn,tm);
		}
		if(y){
			p2=tm-p2+1;
		}
		for(int j=0;j<z;j++){
			t=p1;
			p1=tm-p2+1;
			p2=t;
			swap(tn,tm);
		}
		cout<<p1<<' '<<p2<<'\n';
	}
	return 0;
}