#include<bits/stdc++.h>
using namespace std;
bool ss(int a){
	if(a<2)return 0;
	for(int i=2;i*i<=a;i++)if(a%i==0)return 0;
	return 1;
}
int main(){
	int n,l=4;cin>>n;
	while(1){
		if(!ss(l)&&!ss(l+n)){
			cout<<l+n<<' '<<l<<'\n';return 0;
		}
		l++;
	}
	return 0;
}