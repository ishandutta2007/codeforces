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

ll l,r;
int sllen;
int sl[20];
int srlen;
int sr[20];
int sslen;
int ss[20];

int a[10];
int b[10];
int num;

bool findFirstSmallest(bool sm){
	if(sm || sslen==sllen){
		REP(i,10)while(b[i]){ss[sslen]=i;sslen++;b[i]--;}
		return true;
	}else{
		FOR(j,sl[sslen],10)if(b[j]){
			ss[sslen]=j;
			sslen++;
			b[j]--;
			if(findFirstSmallest(j>sl[sslen-1])) return 1;
			b[j]++;
			sslen--;
		}
		return 0;
	}
}

bool test(int len){
	if(len>srlen) return 0;
	//REP(i,10)cout<<a[i]<<' ';puts("");

	sslen=0;
	if(sllen==len){
		memcpy(b,a,sizeof a);
		if(!findFirstSmallest(0))return 0;
		if(srlen>sllen)return 1;
		REP(k,sslen)if(ss[k]!=sr[k]){
			if(ss[k]<sr[k])return 1;
			return 0;
		}
		return 1;
	}else{
		if(len<srlen) return 1;
		else{
			//len==sr.size()
			int ps=0;
			REP(i,10)if(a[i]){ps=i;break;}
			if(sr[0]>ps) return 1;
			if(sr[0]<ps) return 0;
			memcpy(b,a,sizeof a);
			b[ps]--;
			int dpos=0;
			FOR(j,1,len){
				while(b[dpos]==0)dpos++;
				if(dpos<sr[j])return 1;
				if(dpos>sr[j])return 0;
				b[dpos]--;
			}
			return 1;
		}
	}
}

void go(int pos,int curr){
	if(pos==10){
		if(curr==0)return;
		if(curr>srlen) return;
		a[0]=0;
		if(curr<sllen)a[0]=sllen-curr;

		if(test(curr+a[0])) num++;//,puts("yo"),cout<<endl<<"!"<<ss<<endl;
		else{
			if(curr+a[0]==sllen){
				a[0]++;
				if(test(curr+a[0])) num++;
			}
		}
	}else{
		for(int j=0;j<=18-curr;j++){
			a[pos]=j;
			go(pos+1,curr+j);
			a[pos]=0;
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>l>>r;
	stringstream ss1,ss2;
	ss1<<l;
	string s=ss1.str();
	sllen=s.size();
	REP(i,sllen)sl[i]=s[i]-'0';
	ss2<<r;
	s=ss2.str();
	srlen=s.size();
	REP(i,srlen)sr[i]=s[i]-'0';
	
	go(1,0);

	cout<<num<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}