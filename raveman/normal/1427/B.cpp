//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<int,pii>	p3;
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

int n,k;
string s;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>k>>s;
		REP(i,s.size()){
			if(i-1>=0 && s[i-1]=='W' && s[i]=='L' && i+1<s.size() && s[i+1]=='W' && k){
				s[i]='W';
				k--;
			}
		}
		vector<pii> v;
		REP(i,s.size()){
			if(s[i]=='W' && i+1<s.size() && s[i+1]=='L'){
				int j=i+1;
				while(j<s.size() && s[j]=='L')j++;
				if(j<s.size() && s[j]=='W')v.pb(pii(j-i,i));
			}
		}
		SORT(v);
		REP(i,v.size()){
			int from = v[i].second+1;
			while(from<s.size() && k && s[from]=='L'){
				k--;
				s[from]='W';
				from++;
			}

		}
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='W'){
				int j=i+1;
				while(j<s.size() && k){
					k--;
					s[j]='W';
					j++;
				}
				break;
			}
		}

		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='L' && k){
				k--;
				s[i]='W';
			}
		}
		
		int res=0;
		REP(i,s.size()){
			if(s[i]=='W'){
				res++;
				if(i-1>=0 && s[i-1]=='W')res++;
			}
		}
		cout<<res<<endl;

	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}