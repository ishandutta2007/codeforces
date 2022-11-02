#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
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
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

vi v[26];

bool u[111111];
bool t[111111];
int m;

void solve(int letter,int from,int to){
	//cout<<letter<<' '<<from<<' '<<to<<endl;
	while(to-from>m){
		int pos = lower_bound(v[letter].begin(),v[letter].end(),from+m+1)-v[letter].begin()-1;
		from = v[letter][pos];
		printf("%c",'a'+letter);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	string s;
	cin>>m>>s;

	REP(i,s.size()) v[s[i]-'a'].pb(i);

	REP(i,26){
		memcpy(t,u,sizeof t);
		REP(k,v[i].size()) t[v[i][k]]=true;

		bool good = 1;
		int prev = -1;
		REP(j,s.size()){
			if(t[j])prev=j;
			int len = j - prev;
			if(len>=m){good=0;break;}
		}
		if(good){
			for(int j=0;j<s.size();j++){
				if(u[j])continue;
				int p = j;
				while(p<s.size() && !u[p])++p;
				solve(i,j-1,p);
				j=p;
			}
			break;
		}

		REP(k,v[i].size()) u[v[i][k]]=true,printf("%c",'a'+i);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}