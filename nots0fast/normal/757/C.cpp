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
#define lli long long int
#define double long double
#define MAX 1000010
// #define cout out
// #define cin in
lli inf = pow(10,9);
lli modulo = pow(10,9) + 7;
double eps = 1e-12;
ifstream in;
ofstream out;
struct Trie{
	map<int,Trie> all;
	int sy = 0;
};
int Ins(vector<int> &a, int ind, Trie &wh){
	if(ind==a.size()){
		wh.sy++;
		return wh.sy;
	}
	Trie wh1;
	map<int,Trie> :: iterator it = wh.all.find(a[ind]);
	if(it==wh.all.end())
		wh.all.insert(mp(a[ind],wh1));
	it = wh.all.find(a[ind]);
	return Ins(a,ind+1,(*it).ss);
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> gr[MAX];   // the group that number i belongs to mp(j,k) - in school j i is group k
	lli fkt[MAX];
	fkt[0] = 1;
	for(int i=1; i<MAX; i++){
		fkt[i] = fkt[i-1] * i;
		fkt[i] %= modulo;
	}
	fori(n){
		int g;
		cin>>g;
		forj(g){
			int ed;
			cin>>ed;
			gr[ed].push_back(i);
		}
	} 
	multiset<int> sv;
	Trie tr;
	int sy1 = 0;
	for(int i=1; i<m+1; i++){
		if(gr[i].size()){
			int num = Ins(gr[i],0,tr);
			if(num>1)
				sv.erase(sv.find(num-1));
			sv.insert(num);
		}
		else
			++sy1;
	}
	multiset<int> :: iterator it = sv.begin();
	lli ans = fkt[sy1];
	 ans%=modulo;
	while(it!=sv.end()){
		ans*=fkt[*it];
		ans%=modulo;
		++it;
	}
	cout<<ans;
}