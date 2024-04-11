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

const int maxn = 4000;
LL v[maxn], d[maxn], p[maxn];
vector<int> ans;
queue<int> Q;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i] >> d[i] >> p[i];
	for(int i = 0; i < n; i++){
		if(p[i] >= 0){
			ans.PB(i + 1);
			int cnt = 0;
			for(int j = 0; cnt < v[i] and i + j + 1 < n; j++)
				if(p[i + j + 1] >= 0){
					p[i + j + 1] -= v[i] - cnt, cnt++;
					if(p[i + j + 1] < 0)
						Q.push(i + j + 1);
				}
			while(sz(Q)){
				int id = Q.front();
				Q.pop();
				for(int j = id + 1; j < n; j++)
					if(p[j] >= 0){
						p[j] -= d[id];
						if(p[j] < 0)
							Q.push(j);
					}
			}
		}
	}
	cout << sz(ans) << '\n';
	for(int i = 0; i < sz(ans); i++)
		cout << ans[i] << " \n"[i == sz(ans) - 1];
	return 0;
}