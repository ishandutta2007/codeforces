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

int n;
int a[333][333];
int b[333][333];
int p[333];
int res[333];
int c[333];

set<pii> s;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n) REP(j,n) scanf("%d",&a[i][j]),a[i][j]--,b[i][a[i][j]]=1000-j;
	REP(i,n) scanf("%d",&p[i]),p[i]--;
	CL(res,-1);
	CL(c,-1);
	REP(i,n){
		int pos = -1;
		REP(j,n) if(p[j]==i) pos=j;
		s.insert(pii(pos,i));
		//cout<<"add "<<pos<<' '<<i<<endl;
		pii x = *s.begin();
		REP(j,n){
			if(x.second!=j){
				if(b[j][x.second] > c[j]){
					c[j]=b[j][x.second];
					res[j] = i;
					//cout<<j<<' '<<i<<' '<<c[j]<<endl;
				}
			}
			if(x.second==j){
				if(s.size()>1){
					pii y = *(++s.begin());
					if(b[j][y.second] > c[j]){
						c[j]=b[j][y.second];
						res[j] = i;						
						//cout<<j<<' '<<i<<' '<<c[j]<<endl;
					}
				}
			}
		}
	}

	REP(i,n){
		if(i) printf(" ");
		printf("%d",res[i]+1);
	}
	puts("");
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}