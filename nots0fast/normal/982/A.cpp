#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(lli k=0; k<v; k++)
#define forl(v) for(lli l=0; l<v; l++)
#define fort(v) for(lli t=0; t<v; t++)
#define forz(v) for(lli z=0; z<v; z++)
#define forx(v) for(lli x=0; x<v; x++)
#define lli long long int
#define MAX 1510
#define ch 51
#define double long double
lli inf = pow(10,16);
int modulo = pow(10,9)+7;
double eps = 1e-15;
ifstream in;
ofstream out;
void deal(){
	int n;
	cin>>n;
	int arr[n];
	fori(n){
		char f;
		cin>>f;
		arr[i] = f-'0';
	}
	fori(n){
		if(!arr[i] && ((i-1)<0 || !arr[i-1]) && (i+1==n || !arr[i+1])){
			cout<<"No";
			return;
		} 
		if(arr[i] && ((i-1>-1 && arr[i-1]) || (i+1<n && arr[i+1]))){
			cout<<"No";
			return;
		}
	}
	cout<<"Yes";
}
int main() {
    deal();
}