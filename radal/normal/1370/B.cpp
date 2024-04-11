#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t;
	cin >> t;
	for (ll p=0; p<t; p++){
		ll n;
		cin >> n;
		ll o1=NULL,e1=NULL,ans=0;
		for (ll i=0; i<2*n; i++){
			ll x;
			cin >> x;
			if (ans<n-1){
			
				if (x%2 and o1 == NULL){
					o1 = i+1;
					continue;
				}
				if (x%2 and o1!= NULL){
					cout<<o1<<' '<<i+1<<endl;
					o1 = NULL;
					ans++;
					continue;
				}
				if (1-x%2 and e1 == NULL){
					e1 = i+1;
					continue;
				}
				if (1-x%2 and e1 != NULL){
					cout<<e1<<' '<<i+1<<endl;
					e1 = NULL;
					ans++;
					continue;
				}
			}
		}
	}
}