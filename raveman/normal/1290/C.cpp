#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,int> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,k;
string s;
vi v[333333];

int p[333333];
int d[333333];
int m[2][333333];

int getval(int ver){
	if(m[0][ver]==-1)return m[1][ver];
	else if(m[1][ver]==-1)return m[0][ver];
	return min(m[0][ver],m[1][ver]);
}

int P(int x){
	if(p[x]==x)return x;
	int t =p[x];
	p[x]=P(p[x]);
	d[x]=d[t]^d[x];
	return p[x];
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin>>n>>k;
	REP(i,k){
		d[i]=0;
		p[i]=i;
		m[0][i]=0;
		m[1][i]=1;
	}

	cin>>s;
	REP(i,k){
		int c,x;
		scanf("%d",&c);
		REP(j,c){
			scanf("%d",&x);
			x--;
			v[x].pb(i);
		}
	}


	int sum=0;
	REP(i,n){
		//cout<<"start "<<i<<" = "<<v[i].size()<<endl;
		//REP(j,k)cout<<p[j]<<' '<<d[j]<<' '<<m[0][j]<<' '<<m[1][j]<<endl;
		//cout<<i<<' '<<n<<endl;
		if(v[i].size()==1){
			int pver = P(v[i][0]);
			int d1 = d[v[i][0]];
	//		cout<<"!"<<v[i][0]<<' '<<pver<<' '<<d1<<endl;
			sum -= getval(pver);
			if(s[i]=='0'){
				m[0^d1][pver]=-1;	
			}else{
				m[1^d1][pver]=-1;
			}
			sum += getval(pver); 
		}else if(v[i].size()==2){
			//cout<<"!"<<i<<endl;
			int pver1 = P(v[i][0]);
			int pver2 = P(v[i][1]);
			int d1 = d[v[i][0]];
			int d2 = d[v[i][1]];
	//		cout<<v[i][0]<<' '<<v[i][1]<<' '<<pver1<<' '<<pver2<<' '<<d1<<' '<<d2<<endl;
			if(pver1!=pver2){
				sum -= getval(pver1);
				sum -= getval(pver2);
				//cout<<"="<<sum<<endl;
				int t = (s[i]=='0'?1:0);
				if(m[t^d1^d2][pver2]==-1 || m[0][pver1]==-1)m[0][pver1]=-1;
				else m[0][pver1] += m[t^d1^d2][pver2];
				if(m[1^t^d1^d2][pver2]==-1 || m[1][pver1]==-1)m[1][pver1]=-1;
				else m[1][pver1] += m[1^t^d1^d2][pver2];
				p[pver2]=pver1;
				d[pver2]=(t^d1^d2==0?0:1);
				sum += getval(pver1);
			}
		}

		printf("%d\n",sum);
	}
	//	REP(j,k)cout<<p[j]<<' '<<d[j]<<' '<<m[0][j]<<' '<<m[1][j]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}