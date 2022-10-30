#include<bits/stdc++.h> 
using namespace std;  
int main(){
	long long int t;
	cin >> t;
	for (int p=0; p<t; p++){
		long long int n,ans=0;
		cin >> n;
		while (n!=1){
			ans++;
			if (n%6 == 0){
				n/=6;
			}
			else{
				if (n%3){
					ans=-1;
					break;
				}
				else{
					n*=2;
				}
			}
		}
		cout<<ans<<endl;
	}
}