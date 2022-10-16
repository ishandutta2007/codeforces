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
#define ll long long int
#define double long double
#define MAX 200020
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = 2*pow(10,6);
ll INF = inf;
ll modulo = inf+7;
double eps = 1e-10;
ifstream in;
ofstream out;
int arr[MAX];
namespace n5{
	int aid[MAX] ; 
	vector<int> dsu[MAX];
	int num[MAX];
	void init(int n){
		fori(n)
			aid[i] = i, dsu[i] .pb(i), num[i] = 0;
	}
	void add(int a,int b){
		if(aid[a] == aid[b] )
			return;
		a = aid[a], b = aid[b];
		if(dsu[a].size() < dsu[b].size()){
			int tm = a;
			a = b;
			b = tm;
		}
		forj(dsu[b].size()){
			num[dsu[b][j]] = dsu[a].size();
			dsu[a].pb(dsu[b][j]);
			aid[dsu[b][j]] = a;
		}
		dsu[b].clear();
	}
}
void deal(){
	int n;
	cin>>n;
	n5::init(n);
	fori(n-1){
		int a,b;
		cin>>a>>b;
		--a, --b;
		n5::add(a,b);
	}
	fori(n)
		arr[n5::num[i]] = i;
	fori(n)
		cout<<arr[i]+1<<' ';
	
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}