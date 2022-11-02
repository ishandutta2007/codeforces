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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

char c[333333];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	string s,t;
	cin>>s>>t;
	sort(s.begin(),s.end());
	sort(t.rbegin(),t.rend());
	int n = s.size();
	int pl = 0;
	int pr = n - 1;
	int sb=0;
	int se=(n+1)/2-1;
	int tb=0;
	int te=n/2-1;
	REP(i,n){
		if(i%2==0){
			if(i+1==n)c[pl]=s[sb];
			else{
				if (s[sb]<t[tb]){
					c[pl]=s[sb];
					sb++;
					pl++;
				}else{
					c[pr]=s[se];
					se--;
					pr--;
				}
			}
		}else{
			if(i+1==n)c[pl]=t[tb];
			else{
				if (t[tb]<=s[sb]){
					c[pr]=t[te];
					te--;
					pr--;
				}else{
					c[pl]=t[tb];
					tb++;
					pl++;
				}
			}
		}
	}
	c[n]=0;
	cout<<c<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}

///
//xxxxx
//aaaaa

//xaxax