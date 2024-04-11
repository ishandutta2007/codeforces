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
	int n,m,q;
	cin>>n>>m>>q;
	int dp[n+1] = {};
	string s,t;
	cin>>s>>t;
	for(int i=0; i<s.length(); i++){
		if(i+m>s.length())
			break;
		string zz = "";
		for(int j=i; j<i+m; j++)
			zz+=s[j];
		dp[i+1] = dp[i];	
		if(zz == t)
			dp[i+1]++;
	}
	forz(q){
		int l,r;
		cin>>l>>r;
		if(r-l + 1< m)
			cout<<0<<'\n';
		else
			cout<<dp[r-m+1]-dp[l-1]<<'\n';
	}
}
int main(){
	srand(time(NULL));
	in.open("i.txt");
	out.open("o.txt");
	deal();
}