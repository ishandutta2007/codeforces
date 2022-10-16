#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<(lli)v; i++)
#define forj(v) for(lli j=0; j<(lli)v; j++)
#define fork(v) for(lli k=0; k<(lli)v; k++)
#define forl(v) for(lli l=0; l<(lli)v; l++)
#define fort(v) for(lli t=0; t<(lli)v; t++)
#define forz(v) for(lli z=0; z<(lli)v; z++)
#define lli long long int
#define MAX 500002
#define double long double
#define ch  1430
#define pb push_back
lli inf = 8*pow(10,18);
lli modulo = pow(10,9)+7;
double eps = 1e-8;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
	lli n;
	cin>>n;
	lli arr[n+10][2] = {};
	lli dp[n+10] = {};
	lli sums[2] = {};
	lli sum2[2] = {};
	forj(2)
	fori(n){
		cin>>arr[i][j];
		sums[j]+=arr[i][j];
		dp[i+1]+=arr[i][j];
		if(!j){
			sum2[0]+= i*arr[i][j];
			sum2[1]+=(n-i+n)*arr[i][j];
		}
		else{
			sum2[0]+=(n-i+n-1)*arr[i][j];
			sum2[1]+=(i+1)*arr[i][j];
		}
	}
	for(int i=1; i<=n; i++)
		dp[i]+=dp[i-1];
	sum2[1] -= arr[0][1]  + arr[0][0] * (2*n);
	lli s = 0;
	lli mx = 0;
	fori(n){
		if(i&1){
			mx = max(mx,s+sum2[1]);
			s += (i*2 )*arr[i][1] + (i*2+1)*arr[i][0];
			sum2[1] -= (i*2)*arr[i][1] + (i*2+1)*arr[i+1][1] + (2*n-1)*arr[i][0] + (2*n-2)*arr[i+1][0];
			sum2[1] += 2*(dp[n]-dp[i+2]);
		}
		else{
			mx = max(s+sum2[0],mx);
			s += (i*2 )*arr[i][0] + (i*2 + 1)*arr[i][1];
			sum2[0] -= (i*2 )*arr[i][0] + (i*2+1)*arr[i+1][0] + (2*n-1)*arr[i][1] + (2*n-2)*arr[i+1][1] ;
			sum2[0] += 2*(dp[n] - dp[i+2]);
		}
	}
	mx = max(mx,s);
	cout<<mx;
}
int main(){
	srand(time(NULL));
	in.open("i.txt");
	out.open("o.txt");
	deal();
}