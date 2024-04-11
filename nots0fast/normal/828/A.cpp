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
#define MAX 100001
int inf = pow(10,9);
double eps = pow(10,-18);
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main(){
   int n,a,b;
   cin>>n>>a>>b;
   int ones = 0;
   int say = 0;
   fori(n){
   	int t;
   	cin>>t;
   	if(t==1){
   		if(a)
   			--a;
   		else if(b)
   			--b, ++ones;
   		else if(ones)
   			--ones;
   		else
   			++say;
	}
	else{
		if(b)
			--b;
		else
			say+=2;
	}
   }
   cout<<say;
}