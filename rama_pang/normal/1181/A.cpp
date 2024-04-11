#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main (){
	ll x,y,z;
	cin>>x>>y>>z;
	ll total=0;
	total+= x/z;
	total+= y/z;
	
	ll u= x%z;
	//u= u/z;
	ll v= y%z;
	//v= v%z;
	if (u+v>=z){
		if (u<v){
			cout << ++total << " "<< z-v << endl;
		} else{
			cout << ++total << " "<< z-u << endl;
		}
	} else{
		cout << total << " 0\n";
	}
	//cout << u << " " 
	
}