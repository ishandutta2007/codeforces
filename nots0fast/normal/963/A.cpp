#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define MAX 10
#define ch 3000
#define double long double
int inf = pow(10,9);
lli modulo = pow(10,9)+9;
double eps = 1e-15;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
//int dx[4] = {-1,0,1,0};
//int dy[4] = {0,-1,0,1};
lli pow_mod(lli a, lli b){
	a = a%modulo;
	lli mx = 0;
	fori(63)
		if(((lli)1<<i) & b)
			mx = i;
	lli has = 1;
	for(lli i = mx; i>-1; i--){
		has*=has;
		has%=modulo;
		if(b&((lli)1<<i)){
			has*=a;
			has%=modulo;
		}
	}
	return has;
}
lli calc_up_until(string all,int index, lli a, lli b, lli n, lli start){
	lli s = 0; // start = i
	fori(index){ 
		lli z = pow_mod(a,n-start);
		z *= pow_mod(b,start);
		z%=modulo;
		if(all[i] == '-')
			s-=z;
		else
			s+=z;
		s = (s%modulo + modulo)%modulo;
		++start;
	}
	return s;
}
void deal(){
	int n,a,b,k;
	cin>>n>>a>>b>>k;
	string all;
	cin>>all;
	lli nece = (n+1) / k;
	lli md1 = pow_mod(b,k);
	lli md2 = pow_mod(a,modulo-1-k);
	md1 *= md2; md1%=modulo;
	lli numer = pow_mod(md1,nece) - 1;
	numer = (numer%modulo + modulo)%modulo;
	lli denom = md1 - 1;
//	cout<<"before numer : "<<numer<<endl;
	if(denom == 0)
		numer = nece;
	else{
		numer *= pow_mod(denom,modulo-2);
		numer %= modulo;
	}
	lli S = calc_up_until(all,k,a,b,n,0);
//	cout<<S<<endl;
	S*=numer;
	S%=modulo;
	if(nece*k != (n+1)){
		lli S1 = calc_up_until(all,(n+1)%k,a,b,n,nece*k);
		S+=S1;
		S%=modulo;
	}
	cout<<S;
}
int main() {
	deal();
}