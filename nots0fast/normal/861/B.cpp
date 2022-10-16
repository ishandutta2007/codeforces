#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(10)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define double long double
#define MAX 200001
int inf = pow(10,9);
lli modulo = inf+7;
double eps = 1e-10;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
vector<int> lvl[100];
bool ch(int z){
	fori(100)
		forj(lvl[i].size())
			if(lvl[i][j]>(i+1)*z || lvl[i][j]<=i*z)
				return false;
	return true;
}
int main(){
	int n,m;
	cin>>n>>m;
	fori(m){
		int a,lv;
		cin>>a>>lv;
		--lv;
		lvl[lv].push_back(a);
	}
	set<int> duz;
	for(int i=1; i<201; i++)
		if(ch(i)){
			int sy = n/i;
			if(sy*i!=n)
				++sy;
			duz.insert(sy);
		}
	if(duz.size()==1)
		cout<<(*duz.begin());
	else
		cout<<-1;
}