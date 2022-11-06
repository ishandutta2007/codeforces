#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int 
#define pb push_back

using namespace std;

ll gcd(ll a, ll b ){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (((a/gcd(a,b)))*b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a,b;
	cin>>a>>b;
	ll t=lcm(a,b);
	ll A=a;
	ll B=b;
	ll p=0;
	ll Dasha=0;
	ll Masha=0;
	bool c=a<b;
	while(p<t){
		if(A<B){
			Dasha+=(A-p);
			p=A;
			A+=a;
		}
		else if(B<A){
			Masha+=(B-p);
			p=B;
			B+=b;
		}
		else if(!c){
			Dasha+=(A-p);
			p=A;
			A+=a;
			B+=b;
		}
		else{
			Masha+=(B-p);
			p=A;
			A+=a;
			B+=b;
		}
	}
	if(Dasha>Masha){
		cout<<"Dasha";
	}
	else if(Masha>Dasha){
		cout<<"Masha";
	}
	else{
		cout<<"Equal";
	}
}