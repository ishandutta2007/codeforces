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

int n,k,l;
int a[222];
int p[222];

bool u[222][222][444];
double d[222][222][444];

double go(int pos,int won,int freeplace){
	freeplace=min(freeplace,200);
	if(pos==n) return won>=l && freeplace>=0 ? 1 : 0;
	//cout<<pos<<' '<<won<<' '<<freeplace<<endl;
	if(u[pos][won][freeplace+222]) return d[pos][won][freeplace+222];
	double res = 0;
	res += p[pos]/100. * go(pos+1,won+1, freeplace + a[pos]);
	res += (1-p[pos]/100.) * go(pos+1,won,freeplace);
	u[pos][won][freeplace+222]=true;
	return d[pos][won][freeplace+222]=res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>l>>k;
	REP(i,n) cin>>p[i];
	REP(i,n) cin>>a[i];
	
	printf("%.10lf\n",go(0,0,k));

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}