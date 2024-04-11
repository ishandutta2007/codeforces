#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision(6)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define double long double
#define MAX 100002
int inf = pow(10,9);
lli modulo = inf+7;
double eps = 1e-9;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
bool ok(string &a){
	vector<pair<int,int> > ind(1,mp(0,0));
	for(int i=1; i<a.length(); i++){
		if(a[i]==a[i-1])
		 ind[ind.size()-1].ss++ ;
		else
		 ind.push_back(mp(i,i));
	}
	if(ind.size()<3)
		return 1;
	if(ind.size()==3 && a[0]=='a')
		return 1;
	return 0;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string a;
	cin>>a;
	int sz = a.length();
	int DP[sz][sz][2];
	fori(sz){
		for(int j=i ; j<sz; j++){
			if(j==i){
				fork(2)
					DP[i][j][k] = 0;
			}
			else{
				fork(2)
					DP[i][j][k] = DP[i][j-1][k];
			}
			if(a[j]=='a')
				DP[i][j][0]++;
			else
				DP[i][j][1]++;
		}
	}
	int mx  = 0;
	fori(a.length())
		for(int j=i+1; j<a.length(); j++){
			int cem = DP[0][i][0]+DP[i+1][j][1];
			if(j!=a.length()-1)
				cem+=DP[j+1][a.length()-1][0];
			if(cem>mx)
				mx = cem;
		}
	fori(a.length()){
		int cem = DP[0][i][1];
		if(i!=a.length()-1)
			cem+=DP[i+1][a.length()-1][0];
		mx = max(cem,mx);
	}
	mx = max(mx,DP[0][sz-1][0]);
	cout<<mx;
}