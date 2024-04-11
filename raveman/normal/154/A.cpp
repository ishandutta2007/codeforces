#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

bool OUTPUT_TO_FILE = 0;

string s;
string f[22];
bool shit[33][33];

int d[111111][33];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE) freopen("output.txt","w",stdout);
#endif

	getline(cin,s);
	int k;
	cin>>k;
	REP(i,k){
		cin>>f[i];
		shit[f[i][0]-'a'][f[i][1]-'a'] = true;
		shit[f[i][1]-'a'][f[i][0]-'a'] = true;
	}
	const int inf = 1011111111;
	REP(i,s.size()+1)REP(j,27) d[i][j]=inf;
	d[0][26] = 0;

	REP(i,s.size())REP(j,27) if(d[i][j]!=inf){
		d[i+1][j] = min(d[i+1][j], d[i][j] + 1);
		if(!shit[j][s[i]-'a']){
			d[i+1][s[i]-'a'] = min(d[i+1][s[i]-'a'], d[i][j]);
		}
	}

	int res = d[s.size()][0];
	FOR(i,1,26) res = min(res,d[s.size()][i]);
	cout<<res<<endl;

#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}