//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

LL P[20],
   out[6],
   ans[20];
vector<int> vec[10];
vector<pair<int, pii> > num;

void print(int sz){
	memset(out, 0, sizeof out);
	for(int i = 0; i < sz; i++){
		for(int j = 0; j < num[ans[i]].R.L; j++)
			out[j] += 7 * P[i];
		for(int j = 0; j < num[ans[i]].R.R; j++)
			out[j + num[ans[i]].R.L] += 4 * P[i];
	}
	for(int i = 0; i < 6; i++)
		cout << out[i] << ' ';
	cout << '\n';
	return;
}

bool build(LL rem, int pos = 0){
	if(rem == 0){
		print(pos);
		return true;
	}
	int id = rem % 10;
	for(auto valid : vec[id]){
		int val = num[valid].L;
		if(val > rem) continue;
		ans[pos] = valid;
		if(build((rem - val) / 10, pos + 1))
			return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	P[0] = 1;
	for(int i = 1; i <= 18; i++)
		P[i] = P[i - 1] * 10;
	for(int i = 0; i <= 6; i++)
		for(int j = 0; i + j <= 6; j++){
			vec[(7*i+4*j)%10].PB(sz(num));
			num.PB(MP(7*i+4*j, MP(i, j)));
		}
	int q;
	cin >> q;
	while(q--){
		LL val;
		cin >> val;
		if(!build(val))
			cout << "-1\n";
	}
	return 0;
}