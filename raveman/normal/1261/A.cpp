#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back



int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n,k;
		string s;
		cin>>n>>k>>s;
		k--;
		string res="";
		REP(i,n/2-k)res.pb('(');
		REP(i,n/2-k)res.pb(')');
		REP(i,k)res.pb('('),res.pb(')');
		vector<pii> r;

		REP(i,n)if(res[i]!=s[i]){
			FOR(j,i+1,n)if(s[j]==res[i]){
				reverse(s.begin()+i,s.begin()+j+1);
				r.pb(pii(i,j));
				break;
			}
		}

		cout<<r.size()<<endl;
		REP(i,r.size())printf("%d %d\n",r[i].first+1,r[i].second+1);
	}

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}