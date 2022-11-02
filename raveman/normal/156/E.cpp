#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

bool OUTPUT_TO_FILE = 0;

struct Node{
		Node *next[17];
		int mult;
		Node(){CL(next,0); mult = 1;}
};

vi p;
int n,m;
ll  a[11111];
int d[33333];
char str[33333][33];
int len[33333];
ll  c[33333];

Node *start[20][7];

int getId(char c){
	if(c=='?') return 16;
	if(c>='0' && c<='9') return c-'0';
	return c-'A'+10;
}

void go(Node *curr,int base, vi v,int pr){
	if(!v.size()) return;

	vi t[16];
	REP(i,v.size()) t[i%base].pb(v[i]);
	
	curr->mult = (curr->mult * ll(v[0])) % pr;
	
	vi tt;
	for(int i=0;i<v.size();){
		int j = i;
		ll d = 1;
		while(j<v.size() && j < i+base){
			d = (d*v[j])%pr;
			j++;
		}
		tt.pb(d);
		i=j;
	}
	
	REP(i,16) if(t[i].size()) if(curr->next[i]) go(curr->next[i], base, t[i], pr);
	if(curr->next[16]) go(curr->next[16], base, tt, pr);
}

int P[10];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE)freopen("output.txt","w",stdout);
#endif


	for(int i=2;i<100;i++){
		bool pr = true;
		for(int j=2;j*j<=i;j++)if(i%j==0)pr=0;
		if(pr) p.pb(i);
	}
	REP(i,10) P[i]=1;
	REP(i,p.size()) P[i/4] *= p[i];
	REP(i,20)REP(j,7) start[i][j] = new Node();
	
	
	cin>>n;
	REP(i,n) cin>>a[i];
	cin>>m;
	REP(i,m){
		scanf("%d %s %I64d",&d[i],str[i],&c[i]);
		len[i] = strlen(str[i]);
		reverse(str[i],str[i]+len[i]);
		REP(pr,7){
			Node *curr = start[d[i]][pr];
			REP(j,len[i]){
				int x = getId(str[i][j]);
				if(!curr->next[x]) curr->next[x] = new Node();
				curr = curr->next[x];
			}
		}
	}
	FOR(j,2,17)REP(pr,7){
		vi v;
		REP(i,n)v.pb(a[i]%P[pr]);
		go(start[j][pr], j, v, P[pr]);
	}
	REP(i,m){
		int res = -1;
		REP(pr,7){
			Node *curr = start[d[i]][pr];
			REP(j,len[i]) curr = curr->next[getId(str[i][j])];
			REP(ww,4) if(pr*4+ww<p.size()) if((curr->mult+c[i])%p[pr*4+ww]==0){res=p[pr*4+ww];break;}
			if(res!=-1) break;
		}
		cout<<res<<endl;
	}

#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}