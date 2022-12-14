#include"bits/stdc++.h"
using namespace std;


int n;
int m;
int q;
char buf[1005];
string s;
string t;
vector<int> v;
int main(){
	cin >> n >> m >> q;
	scanf("%s", buf);
	s = buf;
	scanf("%s", buf);
	t = buf;
	for (int i = 0; i + t.size() <= s.size(); i++){
		if (s.substr(i, t.size()) == t){
			v.push_back(i);
		}
	}
	while (q--){
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		--r;
		int lef = lower_bound(v.begin(), v.end(), l)-v.begin();
		int rig = upper_bound(v.begin(), v.end(), r-(int)(t.size())+1)-v.begin();
		printf("%d\n", max(0,rig - lef));
	}
	return 0;
}