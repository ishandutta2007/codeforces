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
#define MAX 200100
#define ch 3000
#define double long double
int inf = pow(10,9);
lli modulo = pow(10,9)+9;
double eps = 1e-15;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
//int dx[4] = {-1,0,1,0};
//int dy[4] = {0,-1,0,1};
vector<int> g[MAX];
vector<int> taken;
vector<int>* dsu[MAX];
int depth[MAX];
bool J(int& a, int& b){
	return depth[a] < depth[b];
}
void add(vector<int>* &a, vector<int>* &b){ // add b to a
	if((*b).size()  > (*a).size()){
		vector<int>* temp = a;
		a = b;
		b = temp;
	}
	forj((*b).size())
		(*a).push_back((*b)[j]);
}
bool dfs(int hd, int pr, int dep){
	dsu[hd] = new vector<int> ();
	depth[hd] = dep;
	int nece = 0;
	fori(g[hd].size()){
		int hr = g[hd][i];
		if(hr== pr)
			continue;
		bool ans = dfs(hr,hd,dep+1);
		nece +=    !ans;
		add(dsu[hd],dsu[hr]);
	}
	if(hd){
		if(nece&1){
			sort((*dsu[hd]).begin(),(*dsu[hd]).end(), J);
			taken.push_back(hd);
			forj((*dsu[hd]).size())	taken.push_back((*dsu[hd])[j]);
			(*dsu[hd]).clear();
			return 1;
		}
		(*dsu[hd]).push_back(hd);
		return 0;
	}
	else{
		if(nece&1)
			return 0;
		taken.push_back(hd);
		sort((*dsu[hd]).begin(),(*dsu[hd]).end(), J);
		forj((*dsu[hd]).size())	taken.push_back((*dsu[hd])[j]);
		(*dsu[hd]).clear();
		return 1;
	}
}
void deal(){
	int n;
	cin>>n;
	fori(n){
		int pr;
		cin>>pr; --pr;
		if(pr>-1)
			g[pr].push_back(i), g[i].push_back(pr);
	}
	if(dfs(0,-1,0)){
		cout<<"YES\n";
		forj(taken.size())
			cout<<taken[j]+1<<'\n';
	}
	else
		cout<<"NO\n";
}
int main() {
	deal();
}