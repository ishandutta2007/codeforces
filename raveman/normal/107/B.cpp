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

int n,m,h;
int a[1111];

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
#ifndef LocalHost
	//freopen("dices.in","r",stdin);
	//freopen("dices.out","w",stdout);
#endif

	cin>>n>>m>>h;h--;
	int sum=0;
	REP(i,m) cin>>a[i],sum+=a[i];
	if(sum<n) puts("-1.0");
	else{
		if(a[h]==1) puts("0");
		else{
			a[h]--;n--;sum--;

			if(sum-a[h]<n) puts("1");
			else{

				double val = 1;
				vi v1,v2;
				FOR(i,2,sum-a[h]+1) v1.pb(i);
				FOR(i,2,sum-n+1) v1.pb(i);

				FOR(i,2,sum+1) v2.pb(i);
				FOR(i,2,sum-a[h]-n+1) v2.pb(i);

				SORT(v1);
				SORT(v2);

				double res = 1;
				REP(i,max(v1.size(),v2.size())){
					if(i<v1.size()) res*=v1[i];
					if(i<v2.size()) res/=v2[i];
				}
				val -= res;
				printf("%.10lf\n",val);
			}
		}
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}