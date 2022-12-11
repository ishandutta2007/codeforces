#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	sort(a.begin(),a.end());
	if(a.size()<b.size()){
//		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		cout<<a<<endl;
		return 0;
	}
	
	string temp;
	for(int i=0;i<a.size();++i){
		temp=a;
		for(int j=a.size()-1;j>i;--j){
			swap(a[i],a[j]);
			sort(a.begin()+i+1,a.end());
			if(a>b) a=temp;
			else break;
			
		}
	}
	cout<<a<<endl;
}