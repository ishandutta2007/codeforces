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

int getcode(char c){
	int q = int(c);
	if(q<0) q += 256;
	return q;
}

int mirror(int code){
	int res = 0;
	REP(i,8)if(code&(1<<i))
		res ^= (1<<(7-i));
	return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif
	
	string s;
	getline(cin,s);

	int prev = 0;
	REP(i,s.size()){
		prev = getcode(s[i]);
		prev = mirror(prev);

		int x = mirror(i?getcode(s[i-1]):0) - prev;
		x%=256;
		if(x<0) x+=256;
		cout<<x<<endl;
	}

 
#ifdef LocalHost
    cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}