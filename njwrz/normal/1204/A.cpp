#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	if(a.size()%2==1){
		for(int i=1;i<a.size();i++){
			if(a[i]=='1'){
				cout<<a.size()/2+1;return 0;
			}
		}
		cout<<a.size()/2;
	}else{
		cout<<a.size()/2;
	}
	return 0;
}