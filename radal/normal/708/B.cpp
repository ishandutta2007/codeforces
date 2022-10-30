#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
using namespace std; 

const int N=1e5; 
string converter(ll n){  
	string s="";
	ll i;    
	for(i=0; n>0; i++){    
		s += char(n%2 + int('0'));    
		n= n/2;  
	}    
	reverse(s.begin(), s.end());
	return s;
}
int counter(string s){
	ll t=0; 
	t += (6-s.size());
	rep (i,0,s.size()){
		if (s[i] == '0'){
			t++;
		}
	}
	return t;
}
int main(){
	ll a,b,c,d;
	ll t=0,t2=0;
	cin >> a >> b >> c >>d;
	d*=2;	
	a*=2;
	if (a+b+c+d == 0){
		cout << 0;
		return 0;
	}
	if (a+b+c == 0 && d > 0){
		if (int(sqrt(d)) * (int(sqrt(d)) + 1) != d){
			//cout << int(sqrt(d)) * int(sqrt(d)) + 1;
			cout << "Impossible";
			return 0;
		}
		rep(i,0,int(sqrt(d))+1){
			cout << 1;
		}
		return 0;
	}

	if (d+b+c == 0 && a > 0){
		if (int(sqrt(a)) * (int(sqrt(a)) + 1) != a){
			//cout << int(sqrt(d)) * int(sqrt(d)) + 1;
			cout << "Impossible";
			return 0;
		}
		rep(i,0,int(sqrt(a))+1){
			cout << 0;
		}
		return 0;
	}
	if (int(sqrt(d)) * (int(sqrt(d)) + 1) != d || int(sqrt(a)) * (int(sqrt(a)) + 1 )!= a){
		//cout << int(sqrt(d)) * int(sqrt(d)) + 1;
		cout << "Impossible";
		return 0;
	}
	d = int(sqrt(d)) + 1;
	a = int(sqrt(a)) + 1;
	if (b+c != a*d){
		cout << "Impossible";
		return 0;
	}
	while (b >= d){
		t++;
		b-=d;
	}
	while (c >= a-t){
		t2++;
		c-= a+t;
	}
	rep(i,0,t){
		cout<<0;
	}
/*
	rep(i,0,t2){
		cout<<1;
	}*/
//	cout<<"wf"<<b<<endl;
	rep(i,0,d){
		cout<<1;
		if (b>0 && d-i-1 == b){
			cout << 0;
			t++;
		}
	}
	rep(i,0,a-t){
		cout<<0;
	}
}