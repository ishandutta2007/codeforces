#include <iostream>
using namespace std;
long long a[4],t1,t2;
int main(){
	cin>>a[1]>>a[2]>>a[3];
	t1=max(max(a[1],a[2]),a[3]);
	cout<<"First\n";
	cout.flush();
	cout<<3*t1-a[1]-a[2]-a[3]<<endl;
	cout.flush();
	while(1){
		cin>>t2;
		if(!t2){
			return 0;
		}
		if(t1^a[t2]){
			cout<<2*t1-a[1]-a[2]-a[3]+a[t2]<<endl;
			cout.flush();
		}
		else{
			a[t2]+=3*t1-a[1]-a[2]-a[3];
			t1=max(max(a[1],a[2]),a[3]);
			cout<<3*t1-a[1]-a[2]-a[3]<<endl;
			cout.flush();
		}
	}
	return 0;
}