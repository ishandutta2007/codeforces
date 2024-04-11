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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
string s[111111];
map<string,int> q;

bool ispal(string s){
	if(s.size()==1)return 1;
	if(s.size()==2)return s[0]==s[1];
	if(s.size()==3)return s[0]==s[2];
	return 0;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		getline(cin,s[0]);
		REP(i,n)getline(cin,s[i]);
		bool isp = 0;
		q.clear();
		REP(i,n)isp|=ispal(s[i]),q[s[i]]++;
		REP(i,n){
			q[s[i]]--;
			if(q[s[i]]==0)q.erase(s[i]);
			if(s[i].size()==2){
				if(q.count(string(1,s[i][1])+string(1,s[i][0]))) isp=1;
				REP(j,26)if(q.count(string(1,'a'+j)+string(1,s[i][1])+string(1,s[i][0]))) isp=1;
			}else if(s[i].size()==3){
				if(q.count(string(1,s[i][2])+string(1,s[i][1])+string(1,s[i][0]))) isp=1;
				if(q.count(string(1,s[i][1])+string(1,s[i][0]))) isp=1;
			}
		}
		puts(isp?"YES":"NO");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}