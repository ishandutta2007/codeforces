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

const int mod = 1000000000+7;

string s;
int n;
int r[501][1<<16];
int t[1<<16],t1[1<<16],t2[1<<16];

int x[22][5];

void add(int& x,int y){
	if((x+=y)>=mod)x-=mod;
}
void sub(int& x,int y){
	if((x-=y)<0)x+=mod;
}

void parse(int& pos){
	//cout<<"process "<<pos<<endl;
	int currpos=pos;
	if(s[currpos]=='('){
		pos++;
		int firstpos=pos;
		parse(pos);
		pos++;
		char op = s[pos];
		pos++;
		pos++;
		int secondpos=pos;
		parse(pos);
		pos++;

		if(op=='|' || op=='?'){
			memcpy(t1,r[firstpos],sizeof t1);
			memcpy(t2,r[secondpos],sizeof t2);
			REP(i,16)REP(m,1<<16)if(m&(1<<i)){
				add(t1[m],t1[m^(1<<i)]);
				add(t2[m],t2[m^(1<<i)]);
			}
			REP(m,1<<16)t[m]=t1[m]*ll(t2[m])%mod;
			REP(i,16)REP(m,1<<16)if(m&(1<<i)){
				sub(t[m],t[m^(1<<i)]);				
			}			
			REP(m,1<<16)add(r[currpos][m],t[m]);
		}
		if(op=='&' || op=='?'){
			memcpy(t1,r[firstpos],sizeof t1);
			memcpy(t2,r[secondpos],sizeof t2);
			REP(i,16)REP(m,1<<16)if(!(m&(1<<i))){
				add(t1[m],t1[m^(1<<i)]);
				add(t2[m],t2[m^(1<<i)]);
			}
			REP(m,1<<16)t[m]=t1[m]*ll(t2[m])%mod;
			REP(i,16)REP(m,1<<16)if(!(m&(1<<i))){
				sub(t[m],t[m^(1<<i)]);				
			}			
			REP(m,1<<16)add(r[currpos][m],t[m]);
		}
	}else{
		if(s[currpos]=='?'){
			REP(tp,2)REP(ps,4){
				int mask=0;
				REP(i,16){
					if(((i&(1<<ps))?1:0)==tp)mask|=(1<<i);
				}
				r[currpos][mask]++;
			}
		}else if(islower(s[currpos])){
			int ps = s[currpos]-'a';
			int mask=0;
			REP(i,16)if(!(i&(1<<ps)))mask|=(1<<i);
			r[currpos][mask]++;
		}else{
			int ps = s[currpos]-'A';
			int mask=0;
			REP(i,16)if((i&(1<<ps)))mask|=(1<<i);
			r[currpos][mask]++;
		}
		pos++;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>s;
	int pos=0;
	parse(pos);

	cin>>n;
	REP(i,n)REP(j,5)cin>>x[i][j];

	int res = 0;
	REP(i,1<<16)if(r[0][i]){
		//cout<<"try "<<i<<endl;
		bool good = true;
		REP(j,n){
			int mask = (x[j][0]?1:0)+(x[j][1]?2:0)+(x[j][2]?4:0)+(x[j][3]?8:0);
			if(((i&(1<<mask))?1:0)!=x[j][4]) good=0;
		}		
		if(good){
			//cout<<i<<endl;
			res+=r[0][i];
		}
		if(res>=mod)res-=mod;
	}
	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}