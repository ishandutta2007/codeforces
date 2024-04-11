//#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
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
typedef pair<int,pii>	p3;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

vi apply(vi c,vi m){
	/*REP(i,c.size())cout<<c[i]<<' ';
	puts("");
	REP(i,m.size())cout<<m[i]<<' ';puts("");
	puts("end");
	*/
	vector<vi> t;
	REP(i,m.size()){
		vi z;
		REP(j,m[i]){
			z.pb(c[0]);
			c.erase(c.begin());
		}
		t.pb(z);
	}
	reverse(t.begin(),t.end());
	REP(i,t.size()){
		REP(j,t[i].size())c.pb(t[i][j]);
	}
	//REP(i,c.size())cout<<c[i]<<' ';puts("");
	//puts("endend");
	return c;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	vi c(n);
	REP(i,n)cin>>c[i];

	vector<vi> r;

	// step0
	if(c[0]!=1 && c.back()!=1){
		vi m;
		REP(i,c.size())if(c[i]==1){
			m.pb(i);
			m.pb(n-i);
			c=apply(c,m);
			break;
		}
		r.pb(m);
	}
	// step1
	while(1){
		if(c[0]==1){
			bool f= 0;
			vi m;
			m.pb(1);
			for(int i=1;i<c.size();i++){
				if(c[i]!=c[i-1]+1){
					f=1;

					for(int j=i;j<c.size();j++){
						if(c[j]==c[i-1]+1){
							m.pb(j-i+1);
							if(n-j-1>0)					m.pb(n-j-1);
							break;
						}
					}

					r.pb(m);
					c=apply(c,m);

					break;
				}
				m.pb(1);
			}
			if(!f)break;
		}else if(c.back()==1){
			bool f= 0;
			vi m;
			m.pb(1);
			for(int i=int(c.size())-2;i>=0;i--){
				if(c[i]!=c[i+1]+1){
					f=1;

					for(int j=i;j>=0;j--){
						if(c[j]==c[i+1]+1){
							m.pb(i+1-j);
							if(j>0)					m.pb(j);
							break;
						}
					}
					reverse(m.begin(),m.end());
					r.pb(m);
					c=apply(c,m);

					break;
				}
				m.pb(1);
			}
			if(!f)break;
		}else{
			puts("fuck");
		}
	}
	// step2
	if(c[0]!=1){
		vi m;
		REP(i,n)m.pb(1);
		r.pb(m);
		c=apply(c,m);
	}
	REP(i,n)if(c[i]!=i+1)puts("fuck2");
	cout<<r.size()<<endl;
	REP(i,r.size()){
		cout<<r[i].size();
		REP(j,r[i].size())cout<<' '<<r[i][j];
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}