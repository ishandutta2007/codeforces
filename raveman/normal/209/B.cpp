#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define pb				push_back

ll a,b,c;

ll go(ll a,ll b,ll c){
	if(b<c) return go(a,c,b);
	if(a<b) return go(b,a,c);
	if(b==0 && c==0) return 0;
	if(b==c) return b;
	ll res = max(max(a,b),c);
	if(c%2==0 && b%2==0) res = min(res, b);
	if(c%2==1 && b%2==1) res = min(res, b);
	return res;	
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	cin>>a>>b>>c;
	cout<<go(a,b,c)<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}