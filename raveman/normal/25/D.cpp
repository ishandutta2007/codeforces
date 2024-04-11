#pragma comment(linker, "/STACK:136777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
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
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

typedef vector<pii> vpi;
int p[1111];
int P(int x){return p[x]==x?x:p[x]=P(p[x]);}
int p2[1111];
int P2(int x){return p2[x]==x?x:p2[x]=P2(p2[x]);}
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	int n;
	cin>>n;
	vpi v;
	REP(i,1111) p[i]=p2[i]=i;
	REP(i,n-1){
		int x,y;
		cin>>x>>y;x--,y--;
		v.pb(pii(x,y));
		p[P(x)]=P(y);
	}
	vpi r1,r2;
	REP(i,v.size()){
		if(P2(v[i].first) == P2(v[i].second)){
			r1.pb(v[i]);

				REP(b,n)
					if(P(0)!=P(b)){
						r2.pb(pii(0,b));
						p[P(0)]=P(b);
						break;

					}
			
		}else p2[P2(v[i].first)]=P2(v[i].second);

	}
	cout<<r1.size()<<endl;
	REP(i,r1.size())
		printf("%d %d %d %d\n",1+r1[i].first,1+r1[i].second,1+r2[i].first,1+r2[i].second);
	return 0;
}