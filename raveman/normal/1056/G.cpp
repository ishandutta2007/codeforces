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

ll w[111111][1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif


	int n,m;ll t,s;
	cin>>n>>m>>s>>t;
		
	while(1){
		//t=1e12;
		//n=100000-rand()%1000;
		//s=rand()%n+1;
		//m=rand()%100+1;
		//n=99611; m=13; s=5076; t=1000000000000ll;

		ll ss=s;
		ll tt=t;

		//ld cl = ld(clock());
		//CL(w,0);//REP(i,n)w[i].clear();
		
		s--;
		ll it = 0;
		bool was = 0;
		int tn = t%n;
		while(t){
			it++;
			if(s<m)s+=tn;
			else s-=tn;
			if(s>=n)s-=n;
			else if(s<0)s+=n;
			if (!was && tn<1111) {
				if(w[s][tn]){
					ll z = w[s][tn];
					z -= t;
					t %= z;
					was=1;
					//cout<<z<<endl;
				}else w[s][tn]=t;
			}
			t--;
			tn--;
			if(tn<0)tn+=n;
		}
		//cout<<it<<endl;
		//if((ld(clock()-cl)/CLOCKS_PER_SEC)>0)cout<<n<<' '<<m<<' '<<ss<<' '<<tt<<' '<<s+1<<' '<<(ld(clock()-cl)/CLOCKS_PER_SEC)<<' '<<it<<endl;
		cout<<s+1<<endl;
		break;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}