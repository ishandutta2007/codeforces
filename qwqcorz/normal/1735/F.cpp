#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const long double eps=1e-10L;

mt19937 rnd(1);
int n,p[N],q[N];
void work() {
	n=rnd()%50+1;
	long double x=rnd()%10,y=rnd()%10;
	cin>>n>>x>>y;
	for (int i=1;i<=n;i++) {
		p[i]=rnd()%10000000+1;
		cin>>p[i];
	}
	for (int i=1;i<=n;i++) {
		q[i]=rnd()%10000000+1;
		cin>>q[i];
	}
	if (x==0&&y==0) {
		for (int i=1;i<=n;i++) {
			cout<<"0\n";
		}
		return;
	} 
	cout.flush();
	multiset<pair<long double,long double>>S;
	S.insert({0,0});
	long double sumx=0,sumy=0;
	for (int i=1;i<=n;i++) {
		S.insert({1.L*q[i]/p[i],p[i]*2});
		x-=p[i],y+=q[i],sumx+=p[i]*2,sumy+=q[i]*2;
		while (x<-1e-7L) {
			assert(!S.empty());
			auto [k,len]=*S.begin();
			S.erase(S.begin());
			long double rest=0;
			if (x+len>eps) {
				rest=x+len;
				len-=rest;
			}
			x+=len;
			y-=k*len;
			sumx-=len;
			sumy-=k*len;
			if (rest>eps) {
				S.insert({k,rest});
			}
		}
		while (y-sumy<-1e-7L) {
			assert(!S.empty());
			auto [k,len]=*S.rbegin();
			S.erase(S.find(*S.rbegin()));
			long double rest=0;
			if (y-sumy+k*len>eps) {
				rest=1.L*(y-sumy+k*len)/k;
				len-=rest;
			}
			sumx-=len;
			sumy-=k*len;
			if (rest>eps) {
				S.insert({k,rest});
			}
		}
		cout<<x+sumx<<"\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout.setf(ios::fixed);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}
/*
1
5 6.0000000000 4.0000000000
7 6 3 3 8
9 9 4 6 5

*/