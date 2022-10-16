#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(4)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define MAX 100010
#define double long double
#define ch 400
int inf = pow(10,9);
lli modulo = pow(10,9)+7;
lli md = pow(10,9)+7;
double eps = 1e-13;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
void deal(){
	lli n;
	cin>>n;
	lli vs[n], ts[n];
	lli DP[n][2] = { }; // 0 - say, 1 - sum of numbers
	lli sumof[n+1] = { };
	fori(n)
		cin>>vs[i];
	fori(n)
		cin>>ts[i], sumof[i+1] += ts[i], sumof[i+1]+=sumof[i];
	fori(n){
		lli a = i, b = n-1;
		if(sumof[n] - sumof[i] <=  vs[i])
			continue;
		while(a<b){
			lli c = (a+b)/2;
			if(sumof[c+1] - sumof[i]>=vs[i])
				b=c;
			else
				a=c+1;
		}
		DP[a][0]++;
		DP[a][1]+=vs[i] - (sumof[a]-sumof[i]);
	}
	lli sum = 0;
	lli say = 0;
	fori(n){
		++say;
		sum+=vs[i];
		sum-=DP[i][1];
		say-=DP[i][0];
		sum-=say*ts[i];
		cout<<say*ts[i] + DP[i][1]<<' ';
	}
}
int main() {
	deal();
}