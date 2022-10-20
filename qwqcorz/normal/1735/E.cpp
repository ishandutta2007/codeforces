#include<bits/stdc++.h>
#define ll long long
using namespace std;

void work() {
	int n;
	cin>>n;
	vector<int>a(n),b(n);
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}
	for (int i=0;i<n;i++) {
		cin>>b[i];
	}
	map<int,vector<pair<int,int>>>mp;
	for (int i=0;i<n;i++) {
		mp[a[0]+b[i]]=vector<pair<int,int>>();
		mp[abs(a[0]-b[i])]=vector<pair<int,int>>();
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			if (mp.count(a[i]+b[j])) {
				mp[a[i]+b[j]].emplace_back(a[i],b[j]);
			}
		}
	}
	multiset<int>d1,d2;
	for (int i=0;i<n;i++) {
		d1.insert(a[i]),d2.insert(b[i]);
	}
	for (auto [x,c]:mp) {
		vector<pair<int,int>>ans;
		multiset<int>t1,t2;
		while (!d1.empty()&&!d2.empty()) {
			if (*d1.rbegin()>*d2.rbegin()) {
				int mx=*d1.rbegin();
				if (d2.find(mx-x)!=d2.end()) {
					d1.erase(d1.find(mx));
					d2.erase(d2.find(mx-x));
					ans.emplace_back(mx,mx-x);
				} else {
					t1.insert(mx);
					d1.erase(d1.find(mx));
				}
			} else {
				int mx=*d2.rbegin();
				if (d1.find(mx-x)!=d1.end()) {
					d1.erase(d1.find(mx-x));
					d2.erase(d2.find(mx));
					ans.emplace_back(-(mx-x),-mx);
				} else {
					t2.insert(mx);
					d2.erase(d2.find(mx));
				}
			}
		}
		while (!d1.empty()) {
			int x=*d1.begin();
			t1.insert(x);
			d1.erase(d1.find(x));
		}
		while (!d2.empty()) {
			int x=*d2.begin();
			t2.insert(x);
			d2.erase(d2.find(x));
		}
		for (auto [u,v]:c) {
			if (t1.find(u)!=t1.end()&&t2.find(v)!=t2.end()) {
				t1.erase(t1.find(u));
				t2.erase(t2.find(v));
				ans.emplace_back(u,-v);
			}
		}
		if ((int)ans.size()<n) {
			for (int i:t1) {
				d1.insert(i);
			}
			for (int i:t2) {
				d2.insert(i);
			}
			for (auto [u,v]:ans) {
				d1.insert(abs(u)),d2.insert(abs(v));
			}
		} else {
			cout<<"YES\n";
			int mn=0;
			for (auto [u,v]:ans) {
				mn=min(mn,min(u,x+v));
			}
			for (auto [u,v]:ans) {
				cout<<u-mn<<' ';
			}
			cout<<"\n"<<-mn<<' '<<x-mn<<"\n";
			return;
		}
	}
	cout<<"NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}