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

vector<pii> res[55];
set<int> ww[55];

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);w
#endif

	int n,w,m;
	cin>>n>>w>>m;

	w*=m;

	int v = n * w / m;
	bool h = 1;

	int pos = 0;
	int q = w;
	REP(i,m){
		int need = v;
		while(need){
			int x = min(need, q);

			need -= x;
			q -= x;

			ww[pos].insert(i);
			if(ww[pos].size()>2) h=0;

			res[i].pb(pii(pos,x));

			if(q==0) pos++,q=w;
		}
	}

	if(h){
		puts("YES");
		REP(i,m){
			REP(j,res[i].size()){
				if(j) printf(" ");
				printf("%d %.6lf",res[i][j].first+1,double(res[i][j].second)/m);
			}
			puts("");
		}
	}else puts("NO");
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}