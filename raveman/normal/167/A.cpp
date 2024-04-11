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



int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,a,d;
	cin>>n>>a>>d;
	double t = 0;
	REP(i,n){
		int dep,v;
		scanf("%d %d",&dep,&v);

		double maxt = double(v)/a;

		double res = 0;

		if(maxt*maxt*a/2 < d){
			res = maxt;
			double dd = d - maxt*maxt*a/2;
			res += dd/ v;
		}else{
			res = sqrt(d*2./a);
		}
		res += dep;
		res = max(res, t);
		t = res;

		printf("%.10lf\n",res);
	}
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}