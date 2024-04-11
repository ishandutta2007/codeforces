#include<bits/stdc++.h>
using namespace std;
string a[2000];
int ff[2000];
bool cmp(string x,string y){
	return x.size()>y.size();
}
int main(){
	int x,n,i;
	cin>>x;
	n=x*2-2;
	int l,maxi=0;bool f=1;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i].size()>maxi){
			maxi=a[i].size();l=i;
		}
		ff[i]=-1;
	}
	for(i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				ff[i]=1;ff[j]=0;
			}
		}
	} 
	int t=l;
	if(ff[l]==0)f=0;
	ff[l]=1;
	for(i=0;i<n;i++){
		if(a[i]==a[l].substr(0,a[i].size())&&ff[i]!=0){
			ff[i]=1;
		}
	}
	maxi=0;l=-1;
	for(i=0;i<n;i++){
		if(ff[i]!=1){
			if(maxi<a[i].length()){
				maxi=a[i].length();l=i;
			}
		}
	}
	for(i=0;i<n;i++){
		if(ff[i]!=1&&a[l].substr(a[l].size()-a[i].size(),a[i].size())!=a[i]){
			f=0;break;
		}
	}
	if(f){
		for(i=0;i<n;i++){
			if(ff[i]!=1){
				cout<<'S';
			}else cout<<'P';
		}
		return 0;
	}
	l=t;
	for(i=0;i<n;i++)ff[i]=-1;
	for(i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				ff[i]=1;ff[j]=0;
			}
		}
	} 
	ff[l]=0;
	for(i=0;i<n;i++){
		if(a[l].substr(a[l].size()-a[i].size(),a[i].size())==a[i]&&ff[i]!=1){
			ff[i]=0;
		}
	}
	for(i=0;i<n;i++){
		if(ff[i]==0){
			cout<<'S';
		}else cout<<'P';
	}
	return 0;
}