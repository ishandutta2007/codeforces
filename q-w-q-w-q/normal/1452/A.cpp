#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int t,x,y;
int ans;
int main(){
	cin>>t;
	while(t--){
		cin>>x>>y;
		if(x>y) x^=y^=x^=y;
		if(x==y) cout<<2*x<<endl;
		else{
			y-=x;
			cout<<2*x+2*y-1<<endl;
		}
	}
}