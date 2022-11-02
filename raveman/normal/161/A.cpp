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

int n,m,x,y;
int a[111111];
int b[111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>x>>y;
	REP(i,n) scanf("%d",a+i);
	REP(i,m) scanf("%d",b+i);
	vector<pii> res;

	int p1 = 0, p2 = 0;
	while(p1<n && p2<m){
		while(p2<m && a[p1]-x > b[p2]) p2 ++;
		if(p2 < m && b[p2] <= a[p1]+y){
			res.pb(pii(p1,p2));
			p1++,p2++;
			continue;
		}
		p1++;
	}

	cout<<res.size()<<endl;
	REP(i,res.size())
		printf("%d %d\n",res[i].first +1 , res[i].second+1);

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}