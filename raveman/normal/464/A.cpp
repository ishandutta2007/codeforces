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

string cont(string curr,char c, int n, int p){
	if(curr.size()>0 && curr.back()==c) return "";
	if(curr.size()>1 && curr[curr.size()-2]==c) return "";
	curr.pb(c);
	while(curr.size()<n){
		bool found = false;
		REP(i,p){
			if(curr.back()-'a'==i) continue;
			if(curr.size()>1 && curr[curr.size()-2]-'a'==i)continue;
			curr.pb('a'+i);
			found=true;
			break;
		}
		if(!found) return "";
	}
	return curr;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,p;
	cin>>n>>p;
	string s;
	cin>>s;
	string res ="";
	for(int i = int(s.size())-1;i>=0;i--){
		FOR(j,s[i]-'a'+1,p){
			string t = cont(s.substr(0,i),'a'+j,n,p);
			if(t!=""){
				res=t;
				break;
			}
		}
		if(res!="")break;
	}
	if(res=="")puts("NO");
	else cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}