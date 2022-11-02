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
	//freopen("output.txt","w",stdout);
#endif

	int t1,t2,x1,x2,t0;
	cin>>t1>>t2>>x1>>x2>>t0;
	if(t1==t2 && t1==t0){
		cout<<x1<<' '<<x2<<endl;
		return 0;
	}
	if(t2==t0){
		cout<<0<<' '<<x2<<endl;
		return 0;
	}
	if(t1==t0){
		cout<<x1<<' '<<0<<endl;
		return 0;
	}

	ll bc = 1e12, bz = 1,b1,b2;
	for(int i=0;i<=x1;i++){
		ll x= i*ll(t0-t1);
		ll z = (t2-t0);
		if(x%z==0) x/=z;
		else x=(x/z)+1;

		x=max(x,0ll);
		if(i==0) x=x2;//max(x,1ll);
		if(x<=x2){
			ll cc = i * ll(t1) + x * ll(t2);
			ll cz = i + x;
			if(bc*cz > cc * bz || bc * cz == cc * bz && cz > bz){
				bz = cz;
				bc = cc;
				b1=i;
				b2=x;
			}
		}
	}
	cout<<b1<<' '<<b2<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}