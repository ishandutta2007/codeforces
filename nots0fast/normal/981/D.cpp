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
#define MAX 100100
#define ch 201
#define double long double
int inf = pow(10,9);
int modulo = pow(10,9)+7;
double eps = 1e-12;
ifstream in;
ofstream out;
vector<int> g[MAX];
void deal(){
	int n,k;
	cin>>n>>k;
	lli arr[n];
	fori(n)
		cin>>arr[i];
	vector<vector<int> > inp;
	lli ed = 0;
	for(int j=60; j>-1; j--){
		ed ^= ((lli)1<<j);
		int dp[n+1][k+1]; // if there are j subsequences ending at i 
		fori(n+1)
			forj(k+1)
				dp[i][j] = 0;
		dp[0][0] = 1;
		fori(n){
			lli s = 0;
			for(int i1=i; i1>-1; i1--){
				s+=arr[i1];
				if((s&ed) == ed){
					for(int x=0; x<k; x++)
						dp[i+1][x+1]|=dp[i1][x];
				}
			}
		}
//		cout<<"the table \n";
//		fori(n+1){
//			forj(k+1)	
//				cout<<dp[i][j]<<' ';
//			cout<<'\n';
//		}
		if(!dp[n][k])
			ed ^= ((lli)1<<j);
	}
	cout<<ed;
}
int main() {
    deal();
}