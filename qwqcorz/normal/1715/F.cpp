#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
double get(bool flag) {
	if (flag) {
		swap(n,m);
	}
	double k=n;
	vector<pair<int,int>>pt;
	pt.emplace_back(-1,0);
	for (int i=0;i<m;i++) {
		pt.emplace_back(n,i);
		pt.emplace_back(0,i+1);
	}
	pt.emplace_back(-1,m);
	cout<<"? "<<pt.size()<<"\n";
	for (auto [x,y]:pt) {
		if (flag) {
			swap(x,y);
		}
		cout<<x<<' '<<y<<"\n";
	}
	cout.flush();
	if (flag) {
		swap(n,m);
	}
	double S;
	cin>>S;
	S=1-S-1/k/2;
	double len=(1/k+S)*k;
	return len-1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(10);
	
	cin>>n>>m;
	double x=get(0),y=get(1);
	cout<<"! "<<x<<' '<<y<<endl;
	
	return 0;
}