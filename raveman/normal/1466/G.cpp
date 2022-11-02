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
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;

char _w[1<<20];
int n,q;
string s0,t;
int mask[111];

int tprecompute[26][111111];
int pw[111111];
int invpw[111111];

map<string,int> cache[20];

int solve(string s, int tok,int fromk=0){
	if(s.size()==0){
		return pw[tok+1];
	}
	if(fromk>tok)return 0;
	if(cache[fromk].count(s))return cache[fromk][s];

	int res = 0;
	if(s.size()==1){
		//cout<<(tprecompute[s[0]-'a'][fromk] - tprecompute[s[0]-'a'][tok+1])<<' '<<tok<<endl;
		res = (tprecompute[s[0]-'a'][fromk] - tprecompute[s[0]-'a'][tok+1]) * ll(invpw[100000-tok]) % mod;
		if(res<0)res+=mod;
	}else{
		REP(d,2){
			bool g=1;
			string rem;
			REP(i,s.size()){
				int pos = i+d;
				if(pos&1){
					rem.pb(s[i]);
				}else{
					if(s[i]!=t[fromk]){g=0;break;}
				}
			}
			if(g){
				res=(res+solve(rem,tok,fromk+1))%mod;
			}
		}
	}

	return cache[fromk][s]=res;
}

ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

int stupid(int k,string w){
	string r=s0;
	REP(i,k)r=r+string(1,t[i])+r;
	int res=0;
	FOR(i,w.size()-1,r.size())
		if(r.substr(i-int(w.size())+1,w.size())==w)res++;
	return res;
}
int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	pw[0]=1;
	FOR(i,1,111111)pw[i]=(pw[i-1]*2)%mod;
	REP(i,111111)invpw[i]=qp(pw[i],mod-2);

	cin>>n>>q;
	cin>>s0>>t;
/*start:
	n=rand()%10+1;
	t="";
	REP(i,n)t.pb('a'+(rand()%3));
	q=1;
	s0="a";
	*/
	CL(tprecompute,0);


	REP(i,t.size())tprecompute[t[i]-'a'][i]=1;
	for(int j=100000;j>=0;j--){
		REP(i,26){
			tprecompute[i][j]=(tprecompute[i][j+1]+tprecompute[i][j]*pw[100000-j])%mod;
		}
	}
	REP(TC,q){
		int k;
		scanf("%d %s",&k,_w);
		string w(_w);
		//k=rand()%(n+1);
		//int tmp = (rand()%10)+1;
		//w.clear();
		//REP(i,tmp)w.pb('a'+(rand()%3));


		int tlen = s0.size() + 1;

		CL(mask,0);
		REP(i,w.size()){
			mask[i%tlen] |= (1<<(w[i]-'a'));
		}
		REP(i,20)cache[i].clear();
		int res = 0;
		REP(i,tlen){
			bool g=1;
			string rw;
			REP(j,w.size()){
				int pos = i+j;
				int pr = pos % tlen;
				if(pr==s0.size()){
					rw.pb(w[j]);
				}else{
					if(w[j]!=s0[pr]){g=0;break;}
				}
			}
			//cout<<i<<' '<<g<<endl;
			if(g){
				res=(res+solve(rw,k-1))%mod;
			}
		}
		/*
		if(res!=stupid(k,w)){
			puts("fuck");
			cout<<res<<' '<<stupid(k,w)<<endl;
			cout<<n<<' '<<q<<endl;
			cout<<s0<<' '<<t<<endl;
			cout<<k<<' '<<w<<endl;
			while(1);
		}
		else{
			cout<<"OK "<<res<<endl;
			goto start;
		}*/
		cout<<res<<'\n';
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}