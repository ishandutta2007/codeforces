#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int n,k;
ll x[1111],y[1111];


int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	
	cin>>n;
	vector<long double> v(n+1);
	v[0] = 1;

	REP(i,n){
		ll x,y;
		cin>>x>>y;

		ll num = 0;

		ll start = 1;
		ll step = 1;

		while(start <= y){
			if(start == 10 * step) step *= 10;
			ll end = start + step - 1;

			ll ss = max(start, x);
			ll ee = min(end, y);
			if(start == step && ss<=ee) num += ee - ss + 1;

			start = end + 1;
		}

		long double prob = num / long double(y-x+1);

		for(int j = n;j>=0;j--)
			v[j] = v[j] * (1 - prob) + (j?v[j-1]:0) * prob;
	}
	cin>>k;

	long double res = 0;


	REP(i,n+1) if(i*100 >= k *n)
		res+=v[i];
	printf("%.12lf\n",double(res));
	return 0;
}