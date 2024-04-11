#include<iostream>

using namespace std;

long long a,b,x,y,z;

int main(){
	cin>>a>>b>>x>>y>>z;
	long long ans=0;
	if(x*2>a){
		ans+=x*2-a;
		a=0;
	}
	else
		a-=x*2;
	if(y>a){
		ans+=y-a;
		a=0;
	}
	else
		a-=y;
	if(y>b){
		ans+=y-b;
		b=0;
	}
	else
		b-=y;
	if(z*3>b){
		ans+=z*3-b;
		b=0;
	}
	else
		b-=z*3;
	cout<<ans<<endl;
	return 0;
}