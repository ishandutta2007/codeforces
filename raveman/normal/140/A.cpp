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

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif

	int n,R,r;
	cin>>n>>R>>r;

	int m = 0;
	if(r>R){}
	else{
		m=1;
		if(r<R){

			int d = R - r;
			int d2 = 2 * r;
			if(d+d>=d2){
				double a = acos(1. - 1./2*d2/d*d2/d);
				double v = 2 * acos(-1.)/a;

				m = max(m,int( v + 1e-8));
			}
		}
	}

	puts(n<=m?"YES":"NO");

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}