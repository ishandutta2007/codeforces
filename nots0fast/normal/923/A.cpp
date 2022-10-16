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
#define MAX 1000010
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
vector<int> divs[MAX];
bool pr[MAX];
void fill(){
	for(int i=2; i<MAX; i++)
		if(!divs[i].size()){
			for(int j=i; j<MAX; j+=i)
				divs[j].push_back(i);
			pr[i] = 1;
		}
}
void deal(){
	fill();
	int x2;
	cin>>x2;
	vector<int > lr;
	forj(divs[x2].size())
		lr.push_back((x2/divs[x2][j] - 1 )* divs[x2][j] + 1);
	lli mn = inf;
	for(lli i=2; i<MAX; i++)
		if(pr[i])
			forj(lr.size()){
				lli fir = lr[j] / i;
				if(fir * i != lr[j])
					fir = (fir+1)*i;
				else
					fir *= i;
				if(fir<=x2 && fir-i+1!=1 ){
					mn = min(mn, fir-i+1);
				}
			}
	cout<<mn;
}
int main() {
	deal();
}