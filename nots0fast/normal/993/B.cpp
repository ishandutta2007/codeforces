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
#define lli long long int
#define MAX 100010
#define double long double
lli inf = pow(10,9)+10;
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int check(vector<pair<int,int> > a, vector<pair<int,int> > b){
	set<int> req;
	fori(a.size()){
		int fir = 0, sec= 0;
		forj(b.size()){
			if(a[i].ff == b[j].ff && a[i].ss == b[j].ss)
				continue;
			if(a[i].ff == b[j].ff || a[i].ff == b[j].ss )
				++fir;
			if(a[i].ss == b[j].ff || a[i].ss == b[j].ss)
				++sec;
		}
		if(fir>0 && sec>0)
			return -1;
		if(fir>0)	req.insert(a[i].ff);
		if(sec>0)	req.insert(a[i].ss);
	}
	if(req.size()==1)	return *req.begin();
	return 0;
} 
void deal(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int> > arr[2];
	fori(n){
		int a,b;
		cin>>a>>b;
		arr[0].push_back(mp(min(a,b), max(a,b)));
	}
	fori(m){
		int a,b;
		cin>>a>>b;
		arr[1].push_back(mp(min(a,b), max(a,b)));
	}
	int guy1 = check(arr[0],arr[1]), guy2 = check(arr[1],arr[0]);
	if(guy1 == -1 || guy2 == -1)
		cout<<-1;
	else 
		cout<<max(guy1,guy2);
}
int main() {
//	while(1)
	deal();
}