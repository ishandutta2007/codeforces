#include <bits/stdc++.h>

using namespace std;

const int N = 70070;
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e6 + 7;

string x[N];
typedef pair < int, pair < long long, long long > > Cancer;

map < Cancer, int > dist[N][9];


map < Cancer, int > cnt;

pair < long long, long long > hashes(string u){
	long long one = 0;
	long long two = 0;

	for(int i = 0; i < u.size(); ++i){
		one = (one * 37 + u[i] - '0') % mod2;
		two = (two * 17 + u[i] - '0') % mod1;
	}

	return make_pair(one, two);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> x[i];
		for(int len = 1; len <= 9; ++len){
			for(int c = 0; c <= 9 - len; ++c){
				Cancer T = make_pair(len, hashes(x[i].substr(c, len)));
				if(dist[i][len].count(T) == 0){
					dist[i][len][T] = c;
					++cnt[make_pair(len, hashes(x[i].substr(c, len)))];
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i){
		for(int len = 1; len <= 9; ++len){
			map < Cancer, int > :: iterator it;
			bool found = false;
			for(it = dist[i][len].begin(); it != dist[i][len].end(); ++it){
				if(cnt[it -> first] == 1){
					for(int c = 0; c < len; ++c){
						cout << x[i][c + it -> second];
					}
					found = true;
					cout << '\n';
					break;
				}
			}
			if(found){
				break;
			}
		}
	}

	return 0;
}