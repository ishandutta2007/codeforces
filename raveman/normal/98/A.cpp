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

string s;
set<string> q;

string rotR(string s){
	swap(s[2],s[5]);
	swap(s[5],s[0]);
	swap(s[0],s[4]);
	return s;
}


string rotU(string s){
	swap(s[0],s[1]);
	swap(s[1],s[2]);
	swap(s[2],s[3]);
	return s;
}

void go(string s){
	if(q.count(s)) return;
	q.insert(s);
	string s1 = rotR(s);
	go(s1);
	string s2 = rotU(s);
	go(s2);
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>s;
	SORT(s);
	int res = 0;
	do{
		if(!q.count(s)){
			res++;
			go(s);
		}
	}while(next_permutation(s.begin(),s.end()));
	cout<<res<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}