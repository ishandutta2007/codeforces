#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

const int mod = 1000;
struct bi{
	int a[61];
	int pos;
	bi(int c=0){
		CL(a,0);
		pos=60;
		a[pos]=c;
	}
	bi pom(bi &s){
		bi r;
		FOR(i,pos,61)FOR(j,s.pos,61)if(i+j-60>=0)
			r.a[i+j-60]+=a[i]*s.a[j];
		for(int i=60;i;i--){
			r.a[i-1]+=r.a[i]/mod,r.a[i]%=mod;
			if(r.a[i]) r.pos=i;
		}
		return r;
	}
	bool bigger(bi &s){
		if(s.pos!=pos) return pos<s.pos;
		FOR(i,pos,61)if(a[i]!=s.a[i]) return a[i]>s.a[i];
		return 0;
	}
	bool isNotNull(){
		return !(pos == 60  && a[pos]==0);
	}
	void out(){
		int p = 0;
		while(p<60 && !a[p])p++;
		cout<<a[p];
		FOR(i,p+1,61) printf("%03d",a[i]);
		puts("");
	}
};

vi v[777];

typedef pair<int,bi> pbi;
vector<pbi> r[1111];
vector<pbi> t;
int n;
bi w[777];

void join(vector<pbi> &v1, vector<pbi> &v2){
	REP(i,n+1) w[i]=0;
	REP(i,v1.size()) REP(j,v2.size()){
		bi e = v1[i].second.pom(v2[j].second);
		if(e.bigger(w[v1[i].first + v2[j].first]))
			w[v1[i].first + v2[j].first]=e;
	}
	v1.clear();
	REP(i,n+1)if(w[i].isNotNull())
		v1.pb(pbi(i,w[i]));
}

void go(int ver,int par=-1){
	vi q;
	REP(i,v[ver].size()) if(v[ver][i]!=par) go(v[ver][i],ver),q.pb(v[ver][i]);
	if(q.size()==0){
		r[ver].pb(pbi(0,1));
		r[ver].pb(pbi(1,1));
	}else{
		t = r[q[0]];
		FOR(i,1,q.size())
			join(t,r[q[i]]);

		bi mx = 0;
		REP(i,t.size()){
			bi e = t[i].second.pom (bi(t[i].first+1));
			if(e.bigger(mx))
				mx=e;
		}
		r[ver].pb(pbi(0,mx));
		REP(i,t.size())
			r[ver].pb(t[i]),r[ver].back().first++;
	}
}

int main(){
    //freopen("input.txt","r",stdin);
	cin>>n;
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	go(0);
	bi res = r[0][0].second;
	res.out();
    return 0;
}