#include <bits/stdc++.h>
using namespace std;
int main(){
	int a1,a2;
	cin>>a1>>a2;
	if(a1==9&&a2==1){
		cout<<"9 10";return 0;
	}
	if(a1==a2-1){
		cout<<a1<<"9 "<<a2<<'0';
	}else if(a1==a2){
		cout<<a1<<"1 "<<a2<<'2';
	}else cout<<-1;
	return 0;
}