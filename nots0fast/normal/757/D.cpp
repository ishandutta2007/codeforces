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
#define MAX 20
// #define cout out
// #define cin in
lli inf = pow(10,9);
int modulo = pow(10,9) + 7;
double eps = 1e-12;
ifstream in;
ofstream out;
int DP[1<<MAX][76]; // ith bit is on = number (i+1) was seen, j - there is a line right after jth element ( indexing starts at 1)
vector<int> nonzero[76];
int main(){
	int n;
	cin>>n;
	fori(1<<MAX)
		forj(n+1)
			DP[i][j] = 0; 
	fori(n+1)
		DP[0][i] = 1, nonzero[i].push_back(0);
	string a;
	cin>>a;
	fori(a.length()){
		int index = i+1;
		int num = 0;
		bool doit = 0;
		for(int j=index-1; j>-1; j--){
			if(a[j]=='1' ){
				if(i-j<5)
					num+=(1<<(i-j));
				else
					num = 0, doit = 1;
			}
			if(doit)
				nonzero[j].clear();
			if(num<=0 || num>20)
				continue;
			fork(nonzero[j].size()){
				int go = nonzero[j][k]|(1<<(num-1));
				if(!DP[go][index])
					nonzero[index].push_back(go);
				DP[go][index]+=DP[nonzero[j][k]][j];
				DP[go][index]%=modulo;
			}
		}
	}
	int sy = 0;
	forj(n+1){
		int wh = 0;
		fori(MAX){
			wh|=(1<<i);
			sy+=DP[wh][j];
			sy%=modulo;
		}
		
	}
	cout<<sy;
}