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
	lli n,x,k;
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	while(cin>>n>>x>>k){
		lli arr[n];
		fori(n)
			cin>>arr[i];
		sort(arr,arr+n);
		lli sy = 0;
		fori(n){
			lli nece = arr[i]/x;
			if(!(arr[i]%x))
				nece+=k-1;
			else
				nece+=k;
			nece*=x;
			int sg = nece+x;
			if(!k){
				if(!(arr[i]%x))
					continue;
				sg = (arr[i]/x+1)*x;
				nece = arr[i];
			}
			if(arr[n-1]<nece)
				continue;
			lli a = 0 , b =  n-1;
			while(a<b){
				int c = (a+b)/2;
				if(arr[c]<nece)
					a=c+1;
				else
					b=c;
			}
			lli st = a;
			a =0, b = n-1;
			nece = sg;
			while(a<b){
				int c = (a+b)/2+1;
				if(arr[c]>=nece)
					b=c-1;
				else
					a=c;
			}
			if(a>=st)
				sy+=a-st+1;
		}
		cout<<sy<<endl;
	}
}