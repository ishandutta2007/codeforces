#include<bits/stdc++.h>

using namespace std;

long long n;

int main(){
	cin>>n;
	long long s=0;
	for(long long i=1,t=1;;i<<=1,t++){
		s+=i;
		if(s>=n){
			cout<<t<<endl;
			return 0;
		}
	}
	return 0;
}