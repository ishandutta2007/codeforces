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
	string a;
	map<char,int> xam; xam['a'] = 1, xam['i'] = 1, xam['o'] = 1, xam['e'] = 1, xam['u'] = 1;
	cin>>a;
	string z = "";
	vector<string> yep;
	int say = 0;
	set<char> kaa;
	fori(a.length()){
		if(!xam[a[i]]){
			kaa.insert(a[i]);
			if(say+1>=3 && kaa.size()>1){
				kaa.clear();
				kaa.insert(a[i]);
				yep.push_back(z), z ="", say = 1;
			}
			else
				++say;
		}
		else
			say = 0, kaa.clear();
		z+=a[i];
	}
	if(z!="")
		yep.push_back(z);
	fori(yep.size())	
		cout<<yep[i]<<' ';
}