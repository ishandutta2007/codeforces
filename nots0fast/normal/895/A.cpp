#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(12)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define double long double
#define MAX 2000001
#define ch 1000
int inf = pow(10,9);
lli modulo = inf+7;
double eps = 1e-9;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int main(){
	int n;
	cin>>n;
	int arr[2*n];
	fori(n){
		cin>>arr[i];
	}
	int mn = inf;
	int st = 0;
	while(st<n){
		int s1 = 0;
		for(int i = st; ; ){
			int s2 = 0;
			for(int j=i; ;){
				s2+=arr[j];
				++j;
				j%=n;
				if(j==st)
					break;
			}
			if(fabs(s1-s2)<mn)
				mn = fabs(s1-s2);
			s1+=arr[i];
			++i;
			i%=n;
			if(i==st)
				break;
		}
		++st;
	}
	cout<<mn;
}