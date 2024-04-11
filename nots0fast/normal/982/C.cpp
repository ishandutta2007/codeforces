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
vector<int> g[MAX];
int Mx[MAX];
bool con[MAX];
void dfs(int hd,int pr){
	Mx[hd] = 0;
	con[hd] = 0;
	int sy = 0;
	fori(g[hd].size()){
		int hr = g[hd][i];
		if(hr==pr)
			continue;
		dfs(hr,hd);
		if(!con[hr])
			++sy;
		else
			++Mx[hd];
		Mx[hd]+=Mx[hr];
	}
	if(sy&1)
		con[hd] = 1; 
}
void deal(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	fori(n-1){
		int a,b;
		cin>>a>>b; --a,--b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0,-1);
	if(!con[0] )
		cout<<-1;
	else
		cout<<Mx[0];
}
int main() {
    deal();
}