#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=3;i<=n;i++){
			int tmp=n-i;
			if(tmp%2==0){
				if(tmp/2+1<i){
					cout<<tmp/2+1<<" "<<i<<" "<<tmp/2-1<<'\n';
					break;
				}
			}
			if(tmp%2==1){
				if(tmp/2+1<i){
					cout<<tmp/2+1<<" "<<i<<" "<<tmp/2<<'\n';
					break;
				}
			}
		}
	}
	return 0;
}