#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
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

int n;
int mx,rg;
bool u[1111];
pii p[1111];

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n>>mx>>rg;
	REP(i,n) scanf("%d %d",&p[i].first,&p[i].second);

	int A = mx;
	int curr = 0;
	vector<pii> res;

	int sub = 0;
	while(mx>0){
		int best = -1;
		REP(i,n)if(!u[i] && p[i].first * A >= 100 * mx){
			if(best==-1 || p[best].second < p[i].second)
				best = i;
		}
		if(best != -1){
			sub += p[best].second;
			u[best] = 1;
			res.pb(pii(curr, best+1));
		}

		if(best==-1 && sub<=rg){
			puts("NO");
			return 0;
		}

		mx -= sub;
		mx += rg;

		curr++;
		if(mx<=0) break;
		
		mx = min(mx, A);

		
	}


	puts("YES");
	cout<<curr<<' '<<res.size()<<endl;
	REP(i,res.size())
		printf("%d %d\n",res[i].first,res[i].second);

	return 0;
}