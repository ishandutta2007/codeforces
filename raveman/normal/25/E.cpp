#pragma comment(linker, "/STACK:136777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())


vector<string> v;
string S,T;
int p[111111];

void go(string s){
	
	
	int curr=-1;
	p[0]=-1;
	for(int i=1;i<s.size();i++){
		while(curr>=0 && s[i]!=s[curr+1]) curr=p[curr];
		if(s[curr+1]==s[i]) curr++;
		p[i]=curr;
	}

	curr=-1;
	REP(i,T.size()){
		while(curr>=0 && T[i]!=s[curr+1]) curr=p[curr];
		if(T[i]==s[curr+1]) curr++;
		if(curr==s.size()-1) return;
	}
	while(curr!=s.size()-1)
		curr++,T.pb(s[curr]);
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif
string s;
	getline(cin,s);
	v.pb(s);
	getline(cin,s);
	v.pb(s);
	getline(cin,s);
	v.pb(s);

	SORT(v);
	int best = v[0].size()+v[1].size()+v[2].size();
	do{
		T=v[0];
		go(v[1]);
		go(v[2]);
		best=min(best,int(T.size()));
	}while(next_permutation(v.begin(),v.end()));

	cout<<best<<endl;
	return 0;
}