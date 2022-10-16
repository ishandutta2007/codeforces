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
#define MAX 100010
#define ch 51
#define double long double
lli inf = pow(10,16);
int modulo = pow(10,9)+7;
double eps = 1e-15;
ifstream in;
ofstream out;
bool J(pair<int,int>& a,pair<int,int>& b){
	return a.ff < b.ff;
}
void deal(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	int bg[n];
	int nd[n];
	bool taken[n] = {};
	fori(n)
		bg[i] = i, nd[i] = i;
	vector<pair<int,int> > all;
	fori(n){
		int ed;
		cin>>ed;
		all.push_back(mp(ed,i));
	}
	sort(all.begin(),all.end(),J);
	int mx = 0;
	int ans;
	multiset<int> lens;
	fori(all.size()){
		int hd = all[i].ss;
		taken[hd] = 1;
		lens.insert(1);
		if(hd && taken[hd-1]){
			lens.erase(lens.find(nd[hd-1]-bg[hd-1]+1));
			lens.erase(lens.find(1));
			bg[hd] = bg[hd-1];
			nd[bg[hd]] = hd;
			lens.insert(nd[hd]-bg[hd]+1);
		}
		if(hd<n-1 && taken[hd+1]){
			lens.erase(lens.find(nd[hd]-bg[hd]+1));
			lens.erase(lens.find(nd[hd+1]-bg[hd+1]+1));
			nd[bg[hd]] = nd[hd+1];
			bg[nd[hd+1]] = bg[hd];
			lens.insert(nd[bg[hd]] - bg[hd] + 1);
		}
		multiset<int> :: iterator it, it1;
		it = lens.begin(), it1 = lens.end(), --it1;
		if(*it1 == *it && lens.size() > mx){
			mx = lens.size();
			ans = all[i].ff;
		}
	}
	cout<<ans+1;
}
int main() {
    deal();
}