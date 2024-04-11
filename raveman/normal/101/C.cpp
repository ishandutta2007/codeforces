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

int x[3],y[3];

ll det(ll a,ll b, ll c,ll d){return a*d-b*c;}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	REP(i,3) cin>>x[i]>>y[i];
	
	REP(i,4){
		swap(x[0],y[0]);
		y[0] = -y[0];

		int a = x[1] - x[0];
		int b = y[1] - y[0];
		ll d = det(x[2], y[2], y[2], -x[2]);
		ll d1 = det(a, y[2], b, -x[2]);
		ll d2 = det(x[2], a, y[2], b);
		if(d==0){
			if(a==0 && b==0){
				puts("YES");
				return 0;
			}
		}else{
			if(d<0) d=-d;
			if(d1%d==0 && d2%d==0){
				puts("YES");
				return 0;
			}
		}
	}

	puts("NO");


#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}