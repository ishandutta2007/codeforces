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
#define MAX 5000001
int inf = pow(10,9);
lli modulo = inf+7;
ifstream in; 
ofstream out;
//#define cin in
//#define cout out
int main(){
	lli arr[MAX] = { };
	arr[0] = 0, arr[1] = 0;
	for(lli i=2; i<MAX; i++)
		if(!arr[i])
			for(lli j=i; j<MAX; j+=i)
				if(!arr[j])
					arr[j] = i;
	lli ar[MAX] ;
	ar[0] = 0, ar[1] = 0;
	for(lli i=2; i<MAX; i++){
		ar[i] = arr[i]*(arr[i]-1)/2;
		ar[i] %= modulo;
		ar[i]*=i/arr[i];
		ar[i]%=modulo;
		ar[i]+=ar[i/arr[i]];
		ar[i] %= modulo;
	}
	lli t, l ,r;
	cin>>t>>l>>r;
	lli hasil = 1;
	lli cem = 0;
	for(lli i=l; i<=r; i++){
		cem+=(lli)ar[i]*hasil;
		cem%=modulo;
		hasil*=t;
		hasil%=modulo;
	}
	cout<<cem;
}