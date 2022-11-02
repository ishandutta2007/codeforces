#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

bool OUTPUT_TO_FILE = 0;

const int mod= 1000000007;

int d[111][111*26];

int n;

int go(int len,int sum){
	if(len==0) return sum==0;
	if(sum<0) return 0;
	if(d[len][sum]!=-1) return d[len][sum];
	int val = 0;
	REP(i,26){
		val += go(len-1,sum-i);
		if(val>=mod) val-=mod;
	}
	return d[len][sum]=val;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE) freopen("output.txt","w",stdout);
#endif

	CL(d,-1);

	int tc;
	cin>>tc;	
	string s;
	getline(cin,s);
	REP(TC,tc){
		getline(cin,s);
		n = s.size();
		int sum = 0;
		REP(i,n) sum += s[i]-'a';

		int res = go(n,sum);
		res --;
		if(res<0) res += mod;
		printf("%d\n",res);
	}

#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}