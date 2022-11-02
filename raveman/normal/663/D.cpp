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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[5555];
int b[5555];
int c[5555];
int best;

int s[5555];

void update(pii& p,int k){
	if(p.first==-1)p.first=k;
	p.second=k;
}

pii getR(int p){
	pii rs(-1,-1);
	for(int k=0;k<=n;k++){
		if(p==500 && n<2*k && 2*k<=2*n) update(rs,k);
		if(p==1000 && n<4*k && 4*k<=2*n) update(rs,k);
		if(p==1500 && n<8*k && 8*k<=2*n) update(rs,k);
		if(p==2000 && n<16*k && 16*k<=2*n) update(rs,k);
		if(p==2500 && n<32*k && 32*k<=2*n) update(rs,k);
		if(p==3000 && 32*k<=n) update(rs,k);
	}
	return rs;
}

pii getS(int *a){
	pii t;
	REP(i,n)if(a[i]>0)t.first++;else if(a[i]<0)t.second++;
	return t;
}

pii prepare(pii r,pii s){
	r.first -= s.first;
	r.second -= s.first;
	pii x;
	x.first = max(r.first,0);
	x.second = min(s.second,r.second);
	return x;
}

int d[99][99][99];
int u[99][99][99];
int now;

void updatebest(int i1,int i2,int i3,int v){
	if(u[i1][i2][i3]!=now)u[i1][i2][i3]=now,d[i1][i2][i3]=v;
	else d[i1][i2][i3]=max(d[i1][i2][i3],v);
}

int getp(int s,int t){return s/250*(250-t);}

void solve(int pa,int pb,int pc){
	REP(i,n){
		s[i]=0;
		if(a[i]!=0)s[i]+=pa*(250-abs(a[i]))/250;
		if(b[i]!=0)s[i]+=pb*(250-abs(b[i]))/250;
		if(c[i]!=0)s[i]+=pc*(250-abs(c[i]))/250;
	}
	pii ra = getR(pa);
	pii rb = getR(pb);
	pii rc = getR(pc);
	if(ra.first==-1 || rb.first==-1 || rc.first==-1) return;
	pii sa = getS(a);
	pii sb = getS(b);
	pii sc = getS(c);
	pii cca = prepare(ra,sa);
	pii ccb = prepare(rb,sb);
	pii ccc = prepare(rc,sc);
	if(cca.first>cca.second || ccb.first>ccb.second || ccc.first>ccc.second)return;
	//cout<<pa<<' '<<pb<<' '<<pc<<endl;
	if(best==1) return;
	int ca = sa.second-cca.first;
	int cb = sb.second-ccb.first;
	int cc = sc.second-ccc.first;
	s[0] += (ca+cb+cc)*100;
	if(s[0]>9000){best=1;return;}

	vector<pii> v;
	REP(i,n)v.pb(pii(-s[i],i));
	sort(v.begin(),v.end());
	REP(i,v.size())if(v[i].second==0){
		v.resize(i);
		break;
	}
	best = min(best, (int)v.size() + 1);
	if(v.size()==0)return;

	now++;
	u[0][0][0]=now;
	d[0][0][0]=0;

	int vv;
	REP(i,v.size()){
		int g = v[i].second;
		int points = -v[i].first;
		if(a[g]>=0 && b[g]>=0 && c[g]>=0) continue;
		for(int i1=ca;i1>=0;i1--)for(int i2=cb;i2>=0;i2--)for(int i3=cc;i3>=0;i3--)if(u[i1][i2][i3]==now){
			vv=1+d[i1][i2][i3];
			//100
			if(a[g]<0 && points - getp(pa,-a[g]) <= s[0]) updatebest(i1+1,i2,i3,vv);
			//010
			if(b[g]<0 && points - getp(pb,-b[g]) <= s[0]) updatebest(i1,i2+1,i3,vv);
			//001
			if(c[g]<0 && points - getp(pc,-c[g]) <= s[0]) updatebest(i1,i2,i3+1,vv);
			//110
			if(a[g]<0 && b[g]<0 && points - getp(pa,-a[g]) - getp(pb,-b[g]) <= s[0]) updatebest(i1+1,i2+1,i3,vv);
			//101
			if(a[g]<0 && c[g]<0 && points - getp(pa,-a[g]) - getp(pc,-c[g]) <= s[0]) updatebest(i1+1,i2,i3+1,vv);
			//011
			if(c[g]<0 && b[g]<0 && points - getp(pc,-c[g]) - getp(pb,-b[g]) <= s[0]) updatebest(i1,i2+1,i3+1,vv);
			//111
			if(a[g]<0 && c[g]<0 && b[g]<0 && points - getp(pc,-c[g]) - getp(pb,-b[g]) - getp(pa,-a[g]) <= s[0]) updatebest(i1+1,i2+1,i3+1,vv);
		}
	}
	//cout<<v.size()<<' '<<ca<<' '<<cb<<' '<<cc<<' '<<ra.first<<' '<<ra.second<<' '<<sa.first<<' '<<sa.second<<endl;
	REP(i1,ca+1)REP(i2,cb+1)REP(i3,cc+1)if(u[i1][i2][i3]==now)best=min(best,(int)v.size()+1-d[i1][i2][i3]);
	//cout<<best<<endl;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>a[i]>>b[i]>>c[i];
	best=n;

	for(int pa=500;pa<=3000;pa+=500){
		for(int pb=500;pb<=3000;pb+=500){
			for(int pc=500;pc<=3000;pc+=500){
				solve(pa,pb,pc);
			}
		}
	}

	cout<<best<<endl;

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}