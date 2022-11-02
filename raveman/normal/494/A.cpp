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

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	string s;
	cin>>s;
	int o=0,c=0;
	REP(i,s.size())
		if(s[i]=='(')o++;
		else if(s[i]==')')c++;
	int h = s.size() - o - c;
	int tot = h;
	string t="";
	REP(i,s.size()){
		if(s[i]!='#')t.pb(s[i]);
		else{
			t.pb(')');
			if(h==1){
				REP(j,o-c-tot)t.pb(')');
			}
			h--;
		}
	}

	int num=0;
	REP(i,t.size())if(t[i]=='(')num++;
	else{num--;if(num<0)break;}
	if(num==0){
		REP(i,tot-1) printf("1\n");
		if(tot>0)cout<<(o-c-tot+1)<<endl;
	}else puts("-1");

#ifdef LocalHost
//	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}