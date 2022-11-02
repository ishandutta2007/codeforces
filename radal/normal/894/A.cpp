#include <iostream>
using namespace std;
int g(int n){
	if (n==1){
		return 1;
	}
	else{
		int t=1,a;
		a=n;
		while(a%2==0){
			a/=2;
			t+=1;
		}
		return t+g(n-1);
	}
	return 0;
}
int main(){
	int t=0;
	string a;
	cin>>a;
	for (int i=0; i<a.size(); i++){
		if (a[i]=='Q'){
			for (int j=i+1; j<a.size(); j++){
				if (a[j]=='A'){
					for (int k=j+1; k<a.size(); k++){
						if (a[k]=='Q'){
							t+=1;
						}
					}
				}
			}
		}
	}
	cout<<t;
}