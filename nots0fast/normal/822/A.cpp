#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(1)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define lli long long int
#define double long double
#define MAX 1001
int inf = pow(10,9);
ifstream in; 
ofstream out;
//#define cin in
//#define cout out
int euler(int a){
	set<int> bolen;
	int qayit = a;
	ella:
	int kok = sqrt(a);
	for(int i=2; i<=kok; i++){
		if(!(a%i)){
			bolen.insert(i);
			a/=i;
			goto ella;
		}
	}
	if(a!=1)
		bolen.insert(a);
	while(bolen.size()){
		qayit/=(*bolen.begin());
		qayit*=(*bolen.begin()-1);
		bolen.erase(bolen.begin());
	}
	return qayit;
}
bool prime ( int a){
	int kok = sqrt(a);
	for(int i=2; i<=kok; i++)
		if(!(a%i))
			return 0;
	return 1;
}
int gcd(int a, int b){
	return !b ? a : gcd(b,a%b);
}
bool temiz(int a){
	while(a>1){
		if(a%5)
			return 0;
		a/=5;
	}
	return 1;
}
int main(){
	int a,b;
	cin>>a>>b;
	a = min(a,b);
	int hasil = 1;
	for(int i=1; i<=a; i++)
		hasil*=i;
		cout<<hasil;
}