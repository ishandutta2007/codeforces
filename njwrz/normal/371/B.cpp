#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(b==0)return a;else return gcd(b,a%b);
}
int main(){
	int a,b;
	cin>>a>>b;
	int t=gcd(a,b);
	a/=t;b/=t;
	int ans=0;
	while(a%2==0){
		a/=2;ans++;
	}
	while(a%3==0){
		a/=3;ans++;
	}
	while(a%5==0){
		a/=5;ans++;
	}
	while(b%2==0){
		b/=2;ans++;
	}
	while(b%3==0){
		b/=3;ans++;
	}
	while(b%5==0){
		b/=5;ans++;
	}
	if(a==1&&b==1){
		cout<<ans;
	}else cout<<-1;
	return 0;
}