#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

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

char s[111111];
int n;
int  g[1<<18];
int ng[1<<18];
int p[1<<18];
int up[1<<18];
int STEP;
int lca[1<<18];

void setLCA(int pos,int val){
	pos+=1<<17;
	while(pos){
		lca[pos] = min(lca[pos],val);
		pos>>=1;
	}
}
int getLCA(int p1,int p2){
	if(p1>=n) return 0;
	if(p2>=n) return 0;
	p1+=(1<<17);
	p2+=(1<<17);
	
	p1++;
	int res = 1<<20;
	while(p1<=p2){
		res = min(res, lca[p1]);
		res = min(res, lca[p2]);
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return res;
}

int getLCAPOS(int p1,int p2,int mn){

	p1+=(1<<17);
	p2+=(1<<17);	
	p1++;
	
	while(p1<=p2){
		if(lca[p1]==mn || lca[p2]==mn){
			int start = p2;
			if(lca[p1]==mn) start=p1;
			while(start<(1<<17))
			{
				if(lca[2*start]==mn) start*=2;
				else start=start*2+1;
			}
			return start-(1<<17);
		}
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
}

bool cmp(int p1,int p2){
	if(STEP==1) return s[p1]<s[p2];
	if(g[p1]!=g[p2]) return g[p1]<g[p2];
	return g[p1+(STEP>>1)]<g[p2+(STEP>>1)];
}

ll solve(int a,int b,int prev=0){
	if(a>b) return 0;
	if(a==b){
		if(n-p[a]<=prev) return 0;
		return n-p[a]-prev;
	}
	int mn = getLCA(a,b);
	int pos = getLCAPOS(a,b,mn);
	//cout<<a<<' '<<b<<' '<<mn<<endl;
	ll res = (mn-prev) * ll(b-a+1)*(b-a+2)/2;
	//cout<<a<<' '<<b<<' '<<mn<<' '<<res<<endl;
	res += solve(a,pos-1,mn);
	res += solve(pos,b,mn);
	return res;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	REP(i,1<<18) lca[i]=1<<20;
	gets(s);
	n=strlen(s);
	REP(i,n) g[i]=1,up[i]=p[i]=i;
	for(STEP=1;STEP<=2*n;STEP<<=1){
		sort(p,p+n,cmp);
		int gcnt=1;
		ng[p[0]] = 1;
		//cout<<getLCA(1,n-1)<<endl;
		FOR(i,1,n){
			if(g[p[i]]!=g[p[i-1]] || cmp(p[i-1],p[i])){
				if(g[p[i]]==g[p[i-1]]){
					//puts("yo");
					//cout<<n<<' '<<STEP<<' '<<s+p[i-1]+(STEP>>1)<<p[i-1]+(STEP>>1)<<' '<<s+p[i]+(STEP>>1)<<p[i]+(STEP>>1)<<' '<<getLCA(up[p[i-1]+(STEP>>1)],up[p[i]+(STEP>>1)])<<endl;
					if(STEP==1) setLCA(i, 0);
					else{
						if(p[i-1]+(STEP>>1)>=n || p[i]+(STEP>>1)>=n)
							setLCA(i, (STEP>>1));
						else setLCA(i, (STEP>>1)+getLCA(up[p[i-1]+(STEP>>1)],up[p[i]+(STEP>>1)]));
					}
				}
				gcnt++;
			}
			ng[p[i]]=gcnt;
		}
		REP(i,n)g[i]=ng[i],up[p[i]]=i;
	}
	//REP(i,n) cout<<(i?getLCA(i-1,i):-1)<<' '<<s+p[i]<<endl;
	cout<<solve(0,n-1)<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}