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

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

string s;
int n;

ll d[2][2][2][2][111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	cin>>s;
	n=s.size();
	d[0][0][0][0][1] = 1;
	d[0][1][1][1][1] = 1;
	d[1][0][0][0][1] = 1;
	d[1][1][0][0][1] = 1;

	ll temp;
	FOR(i,1,n-1)REP(s1,2)REP(s2,2)REP(c1,2)REP(c2,2)if(temp=d[s1][s2][c1][c2][i]){
		//cout<<s1<<' '<<s2<<' '<<c1<<' '<<c2<<' '<<i<<" -> "<<temp<<endl;
		REP(ns,2){
			int nc = 0, pc=c2;
			if(s2==0 && ns==1)pc=1,nc=1;
			if((s2^pc)==s[i]-'A')
				d[s1][ns][c1][nc][i+1] += temp;
		}
	}

	ll res = 0;

	REP(s1,2)REP(s2,2)REP(c1,2)REP(c2,2)if(temp=d[s1][s2][c1][c2][n-1]){
		if(s2 == 0 && s1 == 1) c1 = c2 = 1;
		int t1 = s1 ^ c1;
		int t2 = s2 ^ c2;
		if(s[0]-'A'==t1 && s[n-1]-'A'==t2) res += temp;
		//else cout<<"not "<<temp<<endl;
	}
	cout<<res<<endl;


	
#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}