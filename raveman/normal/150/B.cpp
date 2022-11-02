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

bool OUTPUT_TO_FILE = 0;

const int mod = 1000000007;

int n,m,k;
int p[2222];
int P(int v){return p[v]==v?v:p[v]=P(p[v]);}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE) freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,n) p[i]=i;
	for(int i=0;i<=n-k;i++){
		for(int j=0;j<k/2;j++){
			int p1 = P(i+j);
			int p2 = P(i+k-1-j);
			if(p1!=p2) p[p1] = p2;
		}
	}
	ll res = 1;
	REP(i,n)if(P(i)==i) res *= m, res%=mod;
	cout<<res<<endl;
	
#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}