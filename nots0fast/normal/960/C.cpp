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
lli big(lli x){
	lli a = 1;
	lli sy = 0;
	while(a-1<=x){
		a*=2;
		++sy;
	}
	a/=2;
	--sy;
	return sy;
}
void deal(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	lli x,d;
	cin>>x>>d;
	vector<pair<lli,lli> > inp; // first - which number , second how many times
	while(x){
		lli ed = big(x);
		lli num = (((lli)1<<ed) - 1 );
		lli nece = x / num;
		x -= nece*num;
		inp.push_back(mp(ed,nece));
	}
	vector<lli > arr;
	lli pv = 1;
	fori(inp.size()){
		forj(inp[i].ss){
			fork(inp[i].ff)
				arr.push_back(pv);
			pv+=d+1;
		}
	}
	cout<<arr.size()<<'\n';
	fori(arr.size())
		cout<<arr[i]<<' ';
		
}
int main() {
//	map<int,int> aaa;
//	aaa[1] = 2;
//	aaa.insert(mp(1,3));
//	cout<<aaa[1]<<endl;
	deal();
}