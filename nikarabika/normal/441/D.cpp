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

const int maxn = 3000 + 10;
vector<pii> ans;
int a[maxn], cnt[maxn], compo[maxn];
bool mark[maxn];
int cyccnt, n, m;

void HocusPocus(void){
	memset(mark, false, sizeof mark);
	memset(cnt, 0, sizeof cnt);
	cyccnt = 0;
	for(int i = 1; i <= n; i++) if(!mark[i]){
		int v = i;
		while(!mark[v]){
			mark[v] = true;
			cnt[cyccnt]++;
			compo[v] = cyccnt;
			v = a[v];
		}
		cyccnt++;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	m = n - m;
	HocusPocus();
	while(cyccnt < m){
		for(int i = 1; i <= n; i++){
			if(cnt[compo[i]] != 1){
				for(int j = i + 1; j <= n; j++)
					if(compo[j] == compo[i]){
						ans.PB(MP(i, j));
						swap(a[i], a[j]);
						break;
					}
				break;
			}
		}
		HocusPocus();
	}
	while(cyccnt > m){
		for(int i = 2; i <= n; i++){
			if(compo[i] != compo[1]){
				ans.PB(MP(1, i));
				swap(a[1], a[i]);
				break;
			}
		}
		HocusPocus();
	}
	cout << sz(ans) << '\n';
	for(auto ot : ans)
		cout << ot.L << ' ' << ot.R << ' ';
	return 0;
}