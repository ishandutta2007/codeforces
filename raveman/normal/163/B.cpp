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

const int mod = 1000000007;

string s,t;
struct P{
	int v,m,id;
	bool operator<(const P&s)const{
		if(m!=s.m) return m<s.m;
		return v<s.v;
	}
};

int n,k,h;
P a[111111];
int r[111111];

bool good(double t){
	int cnt = 0;
	int pos = h;
	REP(i,n){
		if(pos <= t * a[i].v){
			r[pos/h] = a[i].id;
			cnt++;
			pos += h;
			if(cnt>=k) return 1;
		}
	}
	return 0;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k>>h;
	REP(i,n) scanf("%d",&a[i].m);
	REP(i,n) scanf("%d",&a[i].v);
	REP(i,n) a[i].id = i;
	sort(a,a+n);
	double a = 0, b = 1e10,best=1e9;
	REP(i,100){
		double m = (a+b)/2;
		if(good(m)) b = m,best=m;
		else a = m;
	}
	good(best);
	FOR(i,1,k+1){
		if(i>1) printf(" ");
		printf("%d",r[i]+1);
	}
	puts("");

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}