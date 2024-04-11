#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y,z,a,b,c;
	cin>>x>>y>>z>>a>>b>>c;
	a-=x;
	if(a<0){
		cout<<"NO";return 0;
	}
	if(a+b<y){
		cout<<"NO";return 0;
	}
	if(a+b-y+c<z){
		cout<<"NO";return 0;
	}
	cout<<"YES";
	return 0;
}