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
#define lli  long long int
#define MAX 51
#define ch 300
#define double long double
lli inf = pow(10,18);
unsigned lli modulo = pow(10,9)+7;
double eps = 1e-7;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	int n,k1,k2;
	cin>>n>>k1>>k2;
	lli arr1[n];
	lli arr2[n];
	fori(n)
		cin>>arr1[i];
	fori(n)
		cin>>arr2[i];
	int left1 = k1, left2 = k2;
	fori(k1+k2){
		lli s = 0;
		fori(n)
			s+=(arr1[i]-arr2[i]) * (arr1[i]-arr2[i]) ;
		lli mn = inf;
		int lz = -1;
		fori(n){
			lli s1 = s - (arr1[i]-arr2[i]) * (arr1[i]-arr2[i]) ;
			s1 += (arr1[i]+1-arr2[i]) * (arr1[i]+1-arr2[i]) ;
			if(s1<mn){
				mn = s1;
				lz = i;
			}
		}
		lli mn1 = inf;
		int lz1 = -1;
		fori(n){
			lli s1 = s - (arr1[i]-arr2[i]) * (arr1[i]-arr2[i]) ;
			s1 += (arr1[i]-1-arr2[i]) * (arr1[i]-1-arr2[i]) ;
			if(s1<mn1){
				mn1 = s1;
				lz1 = i;
			}
		}
		if(mn<mn1 ){
			if(left2)
				arr2[lz]--, --left2;
			else
				arr1[lz]++, --left1;
		}
		else{
			if(left1)
				arr1[lz1]--, --left1;
			else
				arr2[lz1]++, --left2;
		}
	}
	lli s = 0;
	fori(n)
		s+=(arr1[i]-arr2[i])*(arr1[i]-arr2[i]);
	cout<<s;
}
int main() {
//	map<int,int> aaa;
//	aaa[1] = 2;
//	aaa.insert(mp(1,3));
//	cout<<aaa[1]<<endl;
	deal();
}