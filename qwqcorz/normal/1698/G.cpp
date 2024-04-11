#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;

int len;
ull mod=0;
struct poly {
	ull x;
	poly() {
		x=0;
	}
	poly(ll k) {
		x=0;
		for (int i=35;i>=0;i--) {
			x<<=1;
			if (k>>i&1) {
				x|=1;
			}
			if (x>>len&1) {
				x^=mod;
			}
		}
	}
	poly operator *(poly a) {
		ull k=x;
		poly ret;
		for (int i=len;i>=0;i--) {
			ret.x<<=1;
			if (k>>i&1) {
				ret.x^=a.x;
			}
			if (ret.x>>len&1) {
				ret.x^=mod;
			}
		}
		return ret;
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin>>s;
	auto p=s.find('1');
	if (p==s.npos) {
		cout<<"-1\n";
		return 0;
	}
	s=s.substr(p);
	len=(int)s.size()-1;
	for (int i=0;i<=len;i++) {
		if (s[i]=='1') {
			mod^=1llu<<(len-i);
		}
	}
	int k=1<<(s.size()/2+1);
	vector<pair<ull,int>>A(k),B(k);
	poly now(1),x(2);
	for (int i=0;i<k;i++) {
		A[i]={now.x,i};
		now=x*now;
	}
	x=now,now=1;
	for (int i=0;i<k;i++) {
		B[i]={(now=now*x).x,i+1};
	}
	ll ans=1e18;
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	for (int i=0,j=0;i<(int)A.size();i++) {
		while (j+1<(int)B.size()&&B[j].first<A[i].first) {
			j++;
		}
		if (A[i].first==B[j].first) {
			int x=A[i].second,y=B[j].second;
			ans=min(ans,1LL*y*k-x);
		}
	}
	cout<<p+1<<' '<<p+1+ans<<"\n";
	
	return 0;
}