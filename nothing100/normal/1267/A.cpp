#include <bits/stdc++.h>
#define ft(i,a,b) for(int i=(a); i<=(b); ++i)
#define fd(i,a,b) for(int i=(a); i>=(b); --i)
#define fv(i,v) for(size_t i=0; i<(v).size(); ++i)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define OP operator
#define LB lower_bound
#define UB upper_bound
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

typedef pair<LL,int> PLI;
typedef vector<PLI> VPLI;

priority_queue<PLI,VPLI,greater<PLI> > q0,q1;

const int N=200050;
LL a[N],b[N],t[N];
LL now,ans;

void get1(LL &min1, int &m1){
	while (true){
		if (q0.empty()) break;
		PLI p=q0.top(); q0.pop();
		if (a[p.S]<now){
			q1.push(MP(t[p.S],p.S));
			continue;
		}
		min1=p.F;
		m1=p.S;
		break;
	}
	
	while (true){
		if (q1.empty()) break;
		PLI p=q1.top(); q1.pop();
		if (now+t[p.S]>b[p.S]) continue;
		
		if (now+t[p.S]<min1){
			q0.push(MP(min1,m1));
			min1=now+t[p.S];
			m1=p.S;
		} else q1.push(p);
		
		break;
	}
}

void get2(LL &min1, int &m1){
	while (true){
		if (q0.empty()) break;
		PLI p=q0.top(); q0.pop();
		if (a[p.S]<now){
			q1.push(MP(t[p.S],p.S));
			continue;
		}
		min1=p.F;
		m1=p.S;
		break;
	}
}

void putput(int m){
	if (now<a[m]){
		q0.push(MP(a[m]+t[m],m));
		return;
	}
	if (now+t[m]>b[m]) return;
	q1.push(MP(t[m],m));
}

const LL inf=2e18;

int main(){
	int n; scanf("%d",&n);
	ft(i,1,n) scanf("%lld%lld%lld",&a[i],&b[i],&t[i]);
	ft(i,1,n) q0.push(MP(a[i]+t[i],i));
	
	while (true){
		LL min1=inf, min2=inf;
		int m1=0, m2=0;
		get1(min1,m1);
		if (min1==inf) break;
		get2(min2,m2);
		now=max(now,a[m1]);
		LL cnt=(min(min2,b[m1])-now)/t[m1];
		ans+=cnt;
		now+=cnt*t[m1];
		putput(m1);
		putput(m2);
	}
	
	printf("%lld\n",ans);
}