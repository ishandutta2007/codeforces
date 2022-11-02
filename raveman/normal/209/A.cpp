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

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define pb				push_back

const int mod = 1000000007;

int d[1111111][2];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	int n;
	cin>>n;

	d[0][0] = d[0][1] = 1;
	REP(i,n)REP(j,2)if(d[i][j]){
		d[i+1][j] += d[i][j]; d[i+1][j] %= mod;
		if(i%2 != j) d[i+1][j^1] += d[i][j], d[i+1][j^1] %= mod;
	}

	ll res = d[n][0] + d[n][1];
	res %= mod;
	res -= 2;
	if(res<0) res += mod;
	cout<<res<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}