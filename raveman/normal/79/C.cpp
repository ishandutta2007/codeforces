#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

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

string s;
int n;

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	getline(cin,s);
	cin>>n;
	vector<pii> v;
	REP(i,n){
		string b;
		cin>>b;
		REP(j,int(s.size())-(int)b.size()+1){
			bool g = 1;
			REP(k,b.size()) if(b[k]!=s[j+k]){g=0;break;}
			if(g) v.pb(pii(j,j+b.size()));
		}
	}
	SORT(v);
	int start = 0;
	int len = 0;

	int end = s.size();
	int pos = int(v.size())-1;
	for(int i=s.size()-1;i>=0;i--){
		while(pos>=0 && v[pos].first >= i) end = min(v[pos].second-1,end),pos--;
		if(end - i > len) len=end-i,start=i;
	}

	cout<<len<<' '<<start<<endl;
	return 0;
}