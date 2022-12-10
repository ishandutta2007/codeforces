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

const int maxn = 3e5 + 85 - 69;
queue<int> q[maxn];
set<pii> s;
int n, qu;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 0;
	cin >> n >> qu;
	for(int i = 0; i < qu; i++){
		int ty, fi;
		cin >> ty >> fi;
		if(ty == 1){
			fi--;
			q[fi].push(cnt);
			s.insert(MP(cnt, fi));
			cnt++;
		}
		else if(ty == 2){
			fi--;
			while(sz(q[fi])){
				s.erase(MP(q[fi].front(), fi));
				q[fi].pop();
			}
		}
		else{
			while(sz(s) and s.begin()->L < fi)
				q[s.begin()->R].pop(), s.erase(s.begin());
		}
		cout << sz(s) << '\n';
	}
	return 0;
}