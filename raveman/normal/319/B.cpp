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

int n;
int a[111111];
set<int> m;

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	vi curr;
	REP(i,n)scanf("%d",a+i),m.insert(i),curr.pb(i);

	int num = 0;
	while(curr.size()){
		vi next;
		for(int i=curr.size()-1;i>=0;i--){
			int pos = curr[i];
			set<int>::iterator it = m.lower_bound(pos);
			if(it!=m.end() && *it == pos){
				++it;
				if(it!=m.end() && a[*it] < a[pos]){
					next.pb(pos);
					m.erase(it);
				}
			}
		}
		reverse(next.begin(),next.end());
		if(next.size()){
			num++;
			curr=next;
		}else break;
	}
	cout<<num<<endl;
	


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}