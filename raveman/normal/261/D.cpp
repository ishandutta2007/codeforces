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

int k,n,maxb,t;
int b[111111];
short bb[111111];
short r[4500];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>k>>n>>maxb>>t;
	//k=10;
	//n=100000;
	//t=1000000000;
	REP(tc,k){
		vi v;
		//maxb=4490;
		//n=100000;
		REP(i,n) scanf("%d",b+i),v.pb(b[i]);
		UN(v);
		REP(i,n) bb[i]=lower_bound(v.begin(),v.end(),b[i])-v.begin();
		maxb = v.size();
		REP(i,maxb+1) r[i]=maxb;
		r[0]=-1;
		int mb = maxb+1;
		short start = 0;
		int op = 0;
		REP(i,t){
			short ch = mb;
			short *s1 = r + start;
			short *s2 = r + mb;
			REP(j,n)if(bb[j]>=i){
			//	op++;
				short pos = lower_bound(s1,s2,bb[j])-r;
				if(r[pos]>bb[j] && r[pos-1]<bb[j]) r[pos]=bb[j],ch=min(ch,pos);//,cout<<"set "<<pos<<' '<<b[j]<<endl;
			}
//			cout<<ch<<endl;
			start=ch;
			if(ch==mb) break;
		}
//		cout<<op<<endl;
		cout<<lower_bound(r,r+maxb+1,maxb)-r-1<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}