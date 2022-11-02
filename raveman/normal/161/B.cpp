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

int n,k;
int c[1111],t[1111];
vi r[1111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n) scanf("%d %d",c+i,t+i);
	vector<pii> v;
	REP(i,n) if(t[i]==1)v.pb(pii(c[i],i));
	SORT(v);
	reverse(v.begin(),v.end());
	REP(i,v.size()) r[min(i,k-1)].pb(v[i].second);
	int pos = k-1;
	REP(i,k) if(r[i].size()==0){
		pos = i;
		break;
	}
	REP(i,n) if(t[i]==2){
		r[pos].pb(i);
		pos++;
		pos=min(pos,k-1);
	}
	double res = 0;
	REP(i,k){
		int mn = 1000000000;
		ll sum = 0;
		bool hasc = 0;
		REP(j,r[i].size()){
			if(t[r[i][j]]==1) hasc=1;
			mn = min(mn, c[r[i][j]]);
			sum += c[r[i][j]];
		}
		res += sum;
		res -= mn;
		if(hasc) res += mn/2.;
		else res += mn;
	}
	printf("%.1lf\n",res);
	REP(i,k){
		cout<<r[i].size();
		REP(j,r[i].size()) printf(" %d",r[i][j]+1);
		puts("");
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}