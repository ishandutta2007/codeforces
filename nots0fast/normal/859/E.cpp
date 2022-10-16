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
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	lli n;
	cin>>n;
	lli olub[MAX] = { };
	lli g[MAX] = { };
	vector<lli> qow;
	lli sum[MAX] = { };
	lli giren[MAX] = { };
	fori(n){
		lli a,b;
		cin>>a>>b; 
		g[a] = b;
		olub[a] = 1, olub[b] = 1;
		sum[a] = 1, sum[b] = 1;
		giren[b]++;
	}
	fori(MAX)
		if(olub[i] && !giren[i])
			qow.push_back(i);
	fori(qow.size()){
		lli hard = qow[i];
		olub[hard] = 2;
		if(g[hard]){
			lli hara = g[hard];
			sum[hara]+=sum[hard];
			sum[hard] = 0;
			giren[hara]--;
			if(!giren[hara])
				qow.push_back(hara);
		}
	}
	lli has = 1;
	fori(MAX){
		if(olub[i]==1){
			vector<lli> bfs(1,i);
			olub[i] = 3;
			fori(bfs.size()){
				lli hard = bfs[i];
				lli hara = g[hard];
				if(olub[hara]==1)
					olub[hara] = 3, bfs.push_back(hara); 
			}
			if(bfs.size()>1){
				has*=2;
				has%=modulo;
			}
		}
		else if(olub[i]==2 && sum[i]){
			has*=sum[i];
			has%=modulo;
		}
	}
	cout<<has;
}