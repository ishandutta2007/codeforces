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

const int maxn = 1e5 + 85 - 69;
int m;
vector<int> vec[26];
set<int> s;
string str;

int get(int ch, int pos){
	int id = upper_bound(all(vec[ch]), pos) - vec[ch].begin();
	if(id == 0 or vec[ch][id - 1] <= pos - m) return -1;
	return vec[ch][id - 1];
}

int can(int ch){
	vector<int> tmp;
	for(auto seg : s)
		tmp.PB(seg);
	int ret = 0;
	for(int i = 0; i < sz(tmp);){
		int val = get(ch, tmp[i]);
		if(val == -1) return -1;
		ret++;
		while(i < sz(tmp) and val + m > tmp[i]) i++;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> m
		>> str;
	for(int i = 0; i < sz(str); i++){
		vec[str[i]-'a'].PB(i);
		if(i + m <= sz(str))
			s.insert(i + m - 1);
	}
	for(int i = 0; i < 26; i++){
		int val = can(i);
		if(~val){
			while(val--) cout << char('a'+i);
			cout << '\n';
			return 0;
		}
		else{
			for(auto id : vec[i]){
				cout << char('a' + i);
				while(sz(s)){
					auto it = s.lower_bound(id);
					if(it == s.end() or *it >= id + m)
						break;
					s.erase(it);
				}
			}
		}
	}
	return 0;
}