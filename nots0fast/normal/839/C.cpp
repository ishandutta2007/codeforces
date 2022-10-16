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
#define lli long long int
#define double long double
#define MAX 100001
int inf = pow(10,9);
int modulo = inf+7;
double eps = 1e-16;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
vector<vector<int> > g(MAX);
double probs[MAX];
double dep[MAX];
double eht = 0;
void dfs(int hd, int fr){
	if(g[hd].size()==1 && hd){
//		cout<<hd<<" "<<dep[hd]<<" "<<probs[hd]<<endl;
		eht+=dep[hd] * probs[hd];
		return ;
	}
	double pr ;
	if(!hd)
	pr = probs[hd] / g[hd].size();
	else
	pr = probs[hd] / (g[hd].size()-1);
	fori(g[hd].size()){
		int hr = g[hd][i];
		if(hr==fr)
			continue;
		probs[hr] = pr;
		dep[hr] = dep[hd] + 1;
		dfs(hr,hd);
	}
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	fori(n-1){
		int a,b;
		cin>>a>>b;
		--a, --b;
		g[a].push_back(b), g[b].push_back(a);
	}
	probs[0] = 1, dep[0] = 0;
	dfs(0,-1);
	cout<<setp<<eht;
}