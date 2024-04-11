#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	char yy[5]={'a','e','i','o','u'};
	cin>>a>>b;
	if(a.size()!=b.size()){
		cout<<"No";return 0;
	}
	int i,j,f1,f2;
	for(i=0;i<a.size();i++){
		f1=0;
		for(j=0;j<5;j++){
			if(a[i]==yy[j]){
				f1=1;break;
			}
		}
		f2=0;
		for(j=0;j<5;j++){
			if(b[i]==yy[j]){
				f2=1;break;
			}
		}
		if(f1!=f2){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}