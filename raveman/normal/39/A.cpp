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

int solve(pii s1,pii s2){
	int sum = 0;
	
	int a = 0;
	if(s1.second) a++;
	sum += a * s1.first;
	if(!s1.second) a++;

	if(s2.second) a++;
	sum += a * s2.first;
	if(!s2.second) a++;

	return sum;
}

bool cmp(const pii &s1,const pii &s2){
	return solve(s1,s2) > solve(s2,s1);
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	string s;
	int a;
	cin>>a>>s;
	vector<pii> c;
	while(s.size()){
		//cout<<s<<endl;
		bool m = (s[0]=='-');
		if(m) s=s.substr(1);
		int k = 1;
		if(isdigit(s[0])){
			k = 0;
			while(isdigit(s[0]))
				k = 10 * k + s[0] - '0',
				s=s.substr(1);
		}
		if(m) k = -k;

		if(s[0]=='*') s=s.substr(1);
		c.pb(pii(k,s[0]=='+'));
		s=s.substr(3);
		if(s.size() && s[0]=='+') s=s.substr(1);
	}
	sort(c.begin(),c.end(),cmp);


	ll res = 0;
	REP(i,c.size()){
		//cout<<c[i].first<<' '<<c[i].second<<endl;
		if(c[i].second) a++;
		res += a * c[i].first;
		if(!c[i].second) a++;
	}
	cout<<res<<endl;

	return 0;
}