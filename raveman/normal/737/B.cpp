#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,a,b,k;
string s;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>a>>b>>k>>s;
	int total = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='1')continue;
		int j = i;
		while(j<n && s[j]=='0')j++;

		total += (j-i)/b;

		i=j;
	}

	vi r;
	for(int i=0;i<n;i++){
		if(s[i]=='1')continue;
		int j = i;
		while(j<n && s[j]=='0')j++;

		int t = (j-i)/b;
		while(t && total>=a){
			total--;
			t--;
			r.pb(i+b-1);
			i+=b;
		}

		i=j;
	}

	cout<<r.size()<<endl;
	REP(i,r.size()){
		if(i)printf(" ");
		printf("%d",r[i]+1);
	}
	puts("");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}