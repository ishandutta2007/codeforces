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
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
string s1,s2,s3;	

pii parse(string s){
	int t0=0,t1=0;
	REP(i,s.size())if(s[i]=='0')t0++;else t1++;
	return pii(t0,t1);
}

void solve(string s1, string s2, char c){
	int p1=0,p2=0;
	while(p1<s1.size() || p2<s2.size()){
		if(p1==s1.size()){
			while(p2<s2.size()){printf("%c",s2[p2]);p2++;}
			break;
		}
		if(p2==s2.size()){
			while(p1<s1.size()){printf("%c",s1[p1]);p1++;}
			break;
		}
		if(s1[p1]==s2[p2]){
			printf("%c",s1[p1]);
			p1++;
			p2++;
			continue;
		}
		printf("%c",(c=='0'?'1':'0'));
		if(s1[p1]==c)p2++;
		else p1++;
	}
	puts("");
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
		getline(cin,s1);
		getline(cin,s1);
		getline(cin,s2);
		getline(cin,s3);
		
		pii t1 = parse(s1);
		pii t2 = parse(s2);
		pii t3 = parse(s3);

		if(t1.first>=t1.second && t2.first>=t2.second) solve(s1,s2,'0');
		else if(t1.first>=t1.second && t3.first>=t3.second) solve(s1,s3,'0');
		else if(t2.first>=t2.second && t3.first>=t3.second) solve(s2,s3,'0');
		else if(t1.first<=t1.second && t2.first<=t2.second) solve(s1,s2,'1');
		else if(t1.first<=t1.second && t3.first<=t3.second) solve(s1,s3,'1');
		else if(t2.first<=t2.second && t3.first<=t3.second) solve(s2,s3,'1');
		
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}