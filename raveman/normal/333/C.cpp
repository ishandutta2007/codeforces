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

int k,m;

set<int> u;
string s;
void go(vi t){
	if(!m) return;
	if(t.size()==1){
		int val = t[0];
		int tmp = k - val;
		if(tmp>=0 && tmp<10000){
			if(u.count(tmp)) return;
			u.insert(tmp);
			m--;
			printf("%s%04d\n",s.c_str(),tmp);
		}
		return;
	}
	vi z=t;
	z[0] += z[1];
	z.erase(z.begin()+1);
	go(z);
	z=t;
	z[0] *= z[1];
	z.erase(z.begin()+1);
	go(z);
	z=t;
	z[0] -= z[1];
	z.erase(z.begin()+1);
	go(z);
	if(t.size()==4){
		FOR(i,1,4){
			z=t;
			z[i-1]=z[i-1]*10+z[i];
			z.erase(z.begin()+i);
			go(z);
		}
		FOR(i,2,4){
			z=t;
			z[i-2]=z[i-2]*100+z[i-1]*10+z[i];
			z.erase(z.begin()+i-1);
			z.erase(z.begin()+i-1);
			go(z);
		}
	}

}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	cin>>k>>m;
	if(k<100){
		REP(i,1000000){
			vi v;
			int t = i;
			REP(j,6)v.pb(t%10),t/=10;
			reverse(v.begin(),v.end());
			bool has0 = 0;
			REP(j,6)if(v[j]==0)has0=1;
			if(has0){
				if(m){
					t=i;
					REP(j,6)printf("%d",v[j]);
					printf("%02d",k);
					puts("");
					m--;
				}
			}
		}
	}else{
		REP(i1,10)REP(i2,10)REP(i3,10)REP(i4,10){
			vi v;
			u.clear();
			v.pb(i1);v.pb(i2);v.pb(i3);v.pb(i4);
			s.clear();
			s.pb(char('0'+i1));s.pb(char('0'+i2));s.pb(char('0'+i3));s.pb(char('0'+i4));
			go(v);
		}
	}
	//cout<<m<<endl;
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}