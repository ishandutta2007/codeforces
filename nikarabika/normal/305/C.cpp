#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pii;

#define MP make_pair
#define L first
#define R second

int n;
LL ans;
set<pii> s;

void add(int val, int cnt){
	if(cnt == 0)
		return;
	auto it = s.lower_bound(MP(val, 0));
	if(it == s.end() or it->L != val)
		s.insert(MP(val, cnt));
	else{
		pii x = *it;
		s.erase(it);
		x.R += cnt;
		s.insert(x);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		LL x;
		cin >> x;
		add(x, 1);
	}
	LL Last = -1;
	while(s.size()){
		pii x = *s.begin();
		s.erase(s.begin());
		ans += x.L - Last - (x.R & 1);
		Last = x.L;
		add(x.L + 1, x.R / 2);
	}
	cout << ans << endl;
	return 0;
}