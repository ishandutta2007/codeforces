//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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
int sz, n, ans;
vector<int> q;
set<pii> s1[maxn],
	s2[maxn];

void solve(int id){
	if(sz(s1[id]) == 1){
		ans++;
		return;
	}
	auto it1 = s1[id].begin(),
		 it3 = s2[id].begin();
	auto it4 = s2[id].rbegin(),
		 it2 = s1[id].rbegin();
	int cnt1 = 0,
		cnt2 = sz(s1[id]) - 1,
		cnt3 = 0,
		cnt4 = sz(s2[id]) - 1;
	int ty = 0;
	while(cnt2 >= cnt1 or cnt4 >= cnt3){
		if(cnt2 >= cnt1 and ty <= 1){
			if(ty == 0){
				int xval = it1->L;
				it1++;
				if(it1->L - xval >= 2){
					for(int i = 0; i <= cnt1; i++){
						auto an = *s1[id].begin();
						s1[id].erase(s1[id].begin());
						s2[id].erase(MP(an.R, an.L));
						s1[sz].insert(an);
						s2[sz].insert(MP(an.R, an.L));
					}
					q.PB(id);
					q.PB(sz++);
					return;
				}
				cnt1++;
			}
			else{
				int xval = it2->L;
				it2++;
				if(xval - it2->L >= 2){
					for(int i = sz(s1[id]); i > cnt2; i--){
						auto an = *s1[id].rbegin();
						s1[id].erase(an);
						s2[id].erase(MP(an.R, an.L));
						s1[sz].insert(an);
						s2[sz].insert(MP(an.R, an.L));
					}
					q.PB(id);
					q.PB(sz++);
					return;
				}
				cnt2--;
			}
		}
		else if(cnt4 >= cnt3 and ty >= 2){
			if(ty == 2){
				int yval = it3->L;
				it3++;
				if(it3->L - yval >= 2){
					for(int i = 0; i <= cnt3; i++){
						auto an = *s2[id].begin();
						s2[id].erase(s2[id].begin());
						s1[id].erase(MP(an.R, an.L));
						s2[sz].insert(an);
						s1[sz].insert(MP(an.R, an.L));
					}
					q.PB(id);
					q.PB(sz++);
					return;
				}
				cnt3++;
			}
			else{
				int yval = it4->L;
				it4++;
				if(yval - it4->L >= 2){
					for(int i = sz(s1[id]); i > cnt4; i--){
						auto an = *s2[id].rbegin();
						s2[id].erase(an);
						s1[id].erase(MP(an.R, an.L));
						s2[sz].insert(an);
						s1[sz].insert(MP(an.R, an.L));
					}
					q.PB(id);
					q.PB(sz++);
					return;
				}
				cnt4--;
			}
		}
		ty++;
		if(ty == 4) ty = 0;
	}
	ans++;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	q.reserve(1 << 20);
	cin >> n;
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		s1[0].insert(MP(fi, se));
		s2[0].insert(MP(se, fi));
	}
	q.PB(sz++);
	while(sz(q)){
		int id = q.back();
		q.pop_back();
		solve(id);
	}
	cout << ans << endl;
	return 0;
}