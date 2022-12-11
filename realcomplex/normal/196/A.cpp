#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair

bool comp(pair<char,int>a,pair<char,int>b){
	if(a.fi>b.fi||(a.fi==b.fi&&a.se<b.se))return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	pair<char,int>v[n];
	for(int j = 0;j<n;j++){
		v[j] = mp(s[j],j);
	}
	sort(v,v+n,comp);
	int ix = -1;
	for(int i = 0;i<n;i++){
		if(v[i].se>ix){
			ix = v[i].se;
			cout << v[i].fi;
		}
	}
	cout << endl;
	return 0;
}