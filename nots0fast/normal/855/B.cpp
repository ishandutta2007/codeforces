#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(10)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define double long double
#define MAX 200001
lli inf = 3*pow(10,18)+100;
lli modulo = inf+7;
double eps = 1e-10;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	lli mx[3] = { };
	lli cons[3];
	lli arr[n];
	fori(3)
		mx[i] = -inf;
	fori(3)
		cin>>cons[i];
	fori(n)
		cin>>arr[i];
	fori(n){
		if(arr[i]*cons[0]>mx[0])
			mx[0] = arr[i]*cons[0];
		if(arr[i]*cons[1]+mx[0]>mx[1])
			mx[1] = arr[i]*cons[1]+mx[0];
		if(arr[i]*cons[2]+mx[1]>mx[2])
			mx[2] = arr[i]*cons[2]+mx[1];
	}
	cout<<mx[2];
}