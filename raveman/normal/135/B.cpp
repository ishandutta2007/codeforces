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

int x[11],y[11];

bool isR(vector<pii> v){
	vector<int> d;
	REP(i,4){
		int next = (i+1)%4;
		d.pb((v[i].first-v[next].first)*(v[i].first-v[next].first)+(v[i].second-v[next].second)*(v[i].second-v[next].second));
	}
	if(d[0]!=d[2] || d[1]!=d[3]) return 0;

	REP(i,4){
		int prev = (i+3)%4;
		int next = (i+1)%4;

		if((v[prev].first-v[i].first)*(v[next].first-v[i].first)+(v[prev].second-v[i].second)*(v[next].second-v[i].second)) return 0;
	}

	return 1;
}

bool isRec(vector<pii> v){
	SORT(v);
	do{
		if(isR(v)) return 1;
	}while(next_permutation(v.begin(),v.end()));
	return 0;
}

bool isSq(vector<pii> v){
	SORT(v);
	do{
		if(isR(v)){
			vector<int> d;
			REP(i,4){
				int next = (i+1)%4;
				d.pb((v[i].first-v[next].first)*(v[i].first-v[next].first)+(v[i].second-v[next].second)*(v[i].second-v[next].second));
			}
			SORT(d);
			if(d[0]==d.back()) return 1;
		}
	}while(next_permutation(v.begin(),v.end()));
	return 0;
}

int main(){
#ifdef LocalHost

    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif

	REP(i,8) scanf("%d %d",x+i,y+i);

	REP(i,1<<8){
		vector<pii> v1,v2;
		vi t1,t2;
		REP(j,8)if(i&(1<<j)) v1.pb(pii(x[j],y[j])),t1.pb(j);
		else v2.pb(pii(x[j],y[j])),t2.pb(j);
		if(t1.size()!=4) continue;
		if(isSq(v1) && isRec(v2)){
			puts("YES");
			REP(j,4){
				if(j) printf(" ");
				printf("%d",t1[j]+1);
			}
			puts("");
			REP(j,4){
				if(j) printf(" ");
				printf("%d",t2[j]+1);
			}
			puts("");

			return 0;
		}
	}
	puts("NO");

	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}