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

bool OUTPUT_TO_FILE = 0;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE) freopen("output.txt","w",stdout);
#endif

	ll n;
	cin>>n;
	bool pr = true;
	for(ll i = 2;i*i<=n;i++)if(n%i==0){pr=0;break;}
	if(pr){
		cout<<1<<endl<<0<<endl;
	}else{
		ll t = -1;
		ll nn=n;
		vector< pair<ll,int> > v;
		for(ll i=2;i*i<=n;i++)if(n%i==0){
			int c = 0;
			while(n%i==0){
				n/=i;
				c++;
			}
			v.pb(make_pair(i,c));
		}
		if(n!=1) v.pb(make_pair(n,1));

		REP(i,v.size()) if(v[i].second>1){t=v[i].first*v[i].first;break;}
		REP(i,v.size()) REP(j,i) t=v[i].first*v[j].first;

		if(t==nn) cout<<2<<endl;
		else cout<<1<<endl<<t<<endl;
	}
	
#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}