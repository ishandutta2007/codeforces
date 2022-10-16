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
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	map<string,int > xam;
	int n;
	cin>>n;
	string str[n];
	fori(n){
		cin>>str[i];
		set<string> ol;
		for(int bw = 0; bw<str[i].length(); ++bw){
			string yen = "";
			for(int sn = bw; sn<str[i].length(); ++sn)
				yen+=str[i][sn], ol.insert(yen);
		}
		set<string> :: iterator it = ol.begin();
		while(it!=ol.end())
			xam[*it]++, ++it;
	}
	fori(n){
		int len = str[i].length();
		string zz = str[i];
		string* DP[len][len];
		for(int gap = 0; gap<len; ++gap)
			for(int j=0,k=gap; k<len; ++j,++k){
				DP[j][k] = new string();
				if(!gap)
					DP[j][k][0] = str[i][k];
				else
					DP[j][k] = DP[j][k-1], DP[j][k][0]+=str[i][k];
				if(xam[DP[j][k][0]]==1)
					cout<<DP[j][k][0]<<'\n', k = len, gap = len;
			}
	}
}