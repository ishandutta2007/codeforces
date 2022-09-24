#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
vector<long long>v;
int point(long long n){
	long long l,r,p;
	l=0;r=v.size();
	for(;r-l>1;){
		p=(r+l)/2;
		if(v[p]<n)l=p;
		else r=p;
	}
	return l+1;
}
int main(){
	long long i,n,m;
	long long t,ans;
	v.push_back(0);
	for(i=0;;i++){
		t=v[i];
		v.push_back(t*10+4);
		v.push_back(t*10+7);
		if(t>1000000000)break;
	}
	cin>>n>>m;
	long long p;
	ans=0;
	p=point(n);
	ans=v[p]*(v[p]-n+1);
	for(;v[p]<=m;){
		n=v[p]+1;
		p=point(n);
		n=v[p];
		ans+=n*(n-v[p-1]);
	}
	ans-=v[p]*(v[p]-m);
	cout<<ans<<endl;
}