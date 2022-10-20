#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int M=1e6+5;

bool vis[M];
vector<int>pr;
vector<pair<int,int>>fac[M];
void ysgs(int n) {
	for (int i=2;i<=n;i++) {
		if (!vis[i]) {
			pr.emplace_back(i);
			fac[i].emplace_back(i,1);
		}
		for (int j:pr) {
			if (i*j>n) {
				break;
			}
			vis[i*j]=1;
			fac[i*j]=fac[i];
			if (i%j) {
				fac[i*j].emplace_back(j,1);
			} else {
				fac[i*j].back().second++;
			}
		}
	}
}
bool mark[N];
int n,a[N],tot=0;
vector<int>t[M];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ysgs(1e6);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		for (auto [x,y]:fac[a[i]]) {
			t[x].emplace_back(i);
		}
	}
	for (int i:pr) {
		if ((int)t[i].size()>=n-1) {
			vector<pair<int,int>>tmp(n);
			for (int j=1;j<=n;j++) {
				tmp[j-1].second=j;
				for (int x=a[j];x%i==0;x/=i) {
					tmp[j-1].first++;
				}
			}
			nth_element(tmp.begin(),tmp.begin()+1,tmp.end());
			tot+=!mark[tmp[0].second]+!mark[tmp[1].second];
			mark[tmp[0].second]=mark[tmp[1].second]=1;
		} else {
			int cnt=0;
			for (int j:t[i]) {
				cnt+=mark[j];
			}
			for (int j=1;j<=n&&tot-cnt<2;j++) {
				if (!mark[j]&&a[j]%i) {
					mark[j]=1;
					tot++;
				}
			}
		}
	}
	vector<int>b;
	for (int i=1;i<=n;i++) {
		if (mark[i]) {
			b.emplace_back(i);
		}
	}
	int cnt=0;
	vector<pair<int,vector<int>>>ans;
	auto solve=[&](vector<int>a) {
		int n=a.size();
		for (int S=1;S<(1<<n);S++) {
			int siz=__builtin_popcount(S);
			int now=(siz%2?-1:1)*(siz-2);
			cnt+=abs(now);
			vector<int>p;
			for (int i=0;i<n;i++) {
				if (S>>i&1) {
					p.emplace_back(a[i]);
				}
			}
			ans.emplace_back(now,p);
		}
	};
	solve(b);
	cout<<cnt<<"\n";
	for (auto [t,a]:ans) {
		if (t>0) {
			for (int j=1;j<=t;j++) {
				cout<<"0 "<<a.size();
				for (int i:a) {
					cout<<' '<<i;
				}
				cout<<"\n";
			}
		}
		if (t<0) {
			for (int j=1;j<=-t;j++) {
				cout<<"1 "<<a.size();
				for (int i:a) {
					cout<<' '<<i;
				}
				cout<<"\n";
			}
		}
	}
	
	return 0;
}