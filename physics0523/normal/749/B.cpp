#include<bits/stdc++.h>

using namespace std;
using pi=pair<int,int>;

pi fourth(pi a,pi b,pi c){
	return {c.first+(b.first-a.first),c.second+(b.second-a.second)};
}

int main(){
	vector<pi> p(3);
	for(auto &nx : p){
		cin >> nx.first >> nx.second;
	}
	set<pi> res;
	res.insert(fourth(p[0],p[1],p[2]));
	res.insert(fourth(p[0],p[2],p[1]));
	res.insert(fourth(p[1],p[0],p[2]));
	res.insert(fourth(p[1],p[2],p[0]));
	res.insert(fourth(p[2],p[0],p[1]));
	res.insert(fourth(p[2],p[1],p[0]));
	cout << res.size() << '\n';
	for(auto &nx : res){
		cout << nx.first << ' ' << nx.second << '\n';
	}
	return 0;
}