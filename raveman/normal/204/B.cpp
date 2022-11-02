#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
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

int x[111111];
int y[111111];
map<int,int> m,w;
set<int> s;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	REP(i,n){
		scanf("%d %d",&x[i],&y[i]);
		m[x[i]]++;
		s.insert(x[i]);
		if(x[i]!=y[i]){
			w[y[i]]++;
			s.insert(y[i]);
		}
	}
	int best = -1;

	for(set<int>::iterator it = s.begin();it!=s.end();it++){
		int val = *it;
		if(m[val] + w[val] >= (n+1)/2){
			int need = (n+1)/2 - m[val];
			need = max(need, 0);
			if(best==-1 || best > need) best = need;
		}
	}

	cout<<best<<endl;

#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}