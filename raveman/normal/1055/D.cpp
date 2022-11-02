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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
string s[3333];
string s2[3333];
char _tmp[3333];
int iv[3333];
int p[3333];

int getfirstocc(const string& s, const string& t){
	int curr = -1;
	p[0]=-1;
	FOR(i,1,t.size()){
		while(curr>=0 && t[i]!=t[curr+1])curr=p[curr];
		if(t[i]==t[curr+1])curr++;
		p[i]=curr;
	}
	curr=-1;
	REP(i,s.size()){
		while(curr>=0 && s[i]!=t[curr+1])curr=p[curr];
		if(s[i]==t[curr+1])curr++;
		if(curr+1==t.size()) return i+1-t.size();
	}
	return -1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n){
		scanf("%s",_tmp);
		s[i]=_tmp;
	}
	REP(i,n){
		scanf("%s",_tmp);
		s2[i]=_tmp;
	}

	string yo,yo2;
	int len;
	vector<pii> v;
	REP(i,n)if(s[i]!=s2[i]){
		int mp=-1;
		int MP=-1;
		REP(j,s[i].size())if(s[i][j]!=s2[i][j]){
			if(mp==-1)mp=j;
			MP=j;
		}
		string tmp = s[i].substr(mp,MP-mp+1);
		string tmp2 = s2[i].substr(mp,MP-mp+1);
		if(yo.empty()) yo=tmp,yo2=tmp2;
		if(yo!=tmp || yo2!=tmp2){
			puts("NO");
			return 0;
		}
		v.pb(pii(i,mp));
	}
	len=yo.size();
	//left
	while(1){
		bool g = v[0].second>0;
		FOR(i,1,v.size())if(g&&v[i].second>0&&s[v[i].first][v[i].second-1]==s[v[0].first][v[0].second-1]&&s2[v[i].first][v[i].second-1]==s2[v[0].first][v[0].second-1]){}
		else g=0;
		if(g){
			REP(i,v.size())v[i].second--;
		}else break;
	}
	//right
	while(1){
		bool g = v[0].second+len<s[v[0].first].size();
		FOR(i,1,v.size())if(g&&v[i].second+len<s[v[i].first].size()&&s[v[i].first][v[i].second+len]==s[v[0].first][v[0].second+len]&&s2[v[i].first][v[i].second+len]==s2[v[0].first][v[0].second+len]){}
		else g=0;
		if(g){
			len++;
		}else break;
	}

	string from = s[v[0].first].substr(v[0].second,len);
	string to = s2[v[0].first].substr(v[0].second,len);

	CL(iv,-1);
	REP(i,v.size())iv[v[i].first]=v[i].second;
	REP(i,n){
		int pos = getfirstocc(s[i],from);
		if(pos!=iv[i]){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	cout<<from<<endl;
	cout<<to<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}