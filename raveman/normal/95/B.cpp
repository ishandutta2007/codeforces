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

int n;
string s;
string t;
bool go(int pos,int n4,int n7,bool bigger = false){
	if(bigger || pos==n){
		REP(i,n7) t.pb('7');
		REP(i,n4) t.pb('4');
		return true;
	}
	if(n4 &&  s[pos]-'0'<=4 && go(pos+1,n4-1,n7,s[pos]-'0'<4)){
		t.pb('4');
		return 1;
	}
	if(n7 && s[pos]-'0'<=7 && go(pos+1,n4,n7-1,s[pos]-'0'<7)){
		t.pb('7');
		return 1;
	}
	return false;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	getline(cin,s);
	n = s.size();

	if(n%2==1){
		n++;
		REP(i,n/2) printf("4");
		REP(i,n/2) printf("7");
		puts("");
	}else{
		if(!go(0, n/2,n/2)){
			n+=2;
			REP(i,n/2) printf("4");
			REP(i,n/2) printf("7");
		}else{
			reverse(t.begin(),t.end());
			printf("%s",t.c_str());
		}
		puts("");
	}
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}