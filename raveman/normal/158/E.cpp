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

int n,k;
int t[4444];
int d[4444];

int e[4444][4444];

int algo(){
	CL(e,-1);
	e[0][0]=0;
	REP(i,n+1)REP(j,n+1)if(e[i][j]!=-1){
		if(e[i+1][j+1] == -1 || e[i+1][j+1] > e[i][j])
			e[i+1][j+1] = e[i][j];

		int end = e[i][j] + 1;
		end = max(end, t[i]);
		end += d[i] - 1;
		if(e[i+1][j] == -1 || e[i+1][j] > end)
			e[i+1][j] = end;
	}

	int best = 0;
	REP(i,n+1)REP(j,n+1)if(j<=k && e[i][j]!=-1){
		int start = e[i][j]+1;
		//cout<<i<<' '<<j<<' '<<start<<endl;
		int pos = lower_bound(t,t+n,start)-t;

		int add = pos - i ;
		if(add<0) add = 0;

		//cout<<add<<endl;

		int jj = j + add;
		if(jj<=k){
			pos = max(pos, i);
			pos += (k-jj);
			int end = 86400;
			if(pos < n) end = t[pos]-1;

			best = max(best, end - start+1);
		}
	}
	return best;
}

int stupid(){
	int best = 0;
	vi v(n,0);
	REP(i,k) v[i]=1;
	SORT(v);
	do{
		vector<pii> x;
		REP(i,n)if(!v[i]) x.pb(pii(t[i],d[i]));
		if(x.size()==0) best = 86400;
		else {
			int start = 1;
			REP(i,x.size()){
				if(x[i].first>start) best = max(best, x[i].first - start), start = x[i].first + x[i].second;
				else start += x[i].second;
			}
			best = max(best, 86400 - start + 1);
		}
	}while(next_permutation(v.begin(),v.end()));
	return best;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE)freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n) cin>>t[i]>>d[i];
	cout<<algo()<<endl;
	/*start:

	//cin>>n>>k;
	n=rand()%10+1;k=rand()%(n+1);
	REP(i,n){
		cin>>t[i]>>d[i];
		t[i]=rand()%86400+1;
	
		d[i]=rand()%86400+1;
	}
	sort(t,t+n);
	if(rand()%10==0) t[0]=1;
	
	cout<<algo()<<' '<<stupid()<<endl;
	if(algo()==stupid()) 
		goto start;
	cout<<n<<' '<<k<<endl;
	REP(i,n) cout<<t[i]<<' '<<d[i]<<endl;
	*/
#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}