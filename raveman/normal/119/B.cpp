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

int n,k;
int a[111];
bool u[111];
int q;

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n) cin>>a[i];
	cin>>q;
	double mn = 1e100;
	double mx = 0;
	REP(i,q){
		int sum = 0;
		REP(j,n/k){
			int x;
			scanf("%d",&x);
			sum+=a[x-1];
			u[x-1]=true;
		}
		double s = double(sum)/(n/k);
		mn = min(mn, s);
		mx = max(mx, s);
	}
	vi v;
	REP(i,n)if(!u[i]) v.pb(a[i]);
	SORT(v);
	if(v.size()>=n/k && n-v.size()!=n/k*k){
		double s = 0;
		REP(i,n/k) s+=v[i];
		mn = min(mn, s/(n/k));
		s=0;

		REP(i,n/k) s+=v[v.size()-1-i];
		mx = max(mx, s/(n/k));
	}

	printf("%.10lf %.10lf\n",mn,mx);

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}