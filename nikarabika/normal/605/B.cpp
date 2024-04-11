#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#undef last
#define last Last

const int maxn = 1e5 + 85 - 69;
pii ans[maxn];
int edge[maxn], a[maxn], b[maxn];
int n, m, last;

bool cmp(int i, int j){
	if(a[i] == a[j])
		return b[i] > b[j];
	return a[i] < a[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		edge[i] = i;
	}
	sort(edge, edge + m, cmp);
	pii an(1, 3);
	last = 1;
	for(int i = 0; i < m; i++){
		int id = edge[i];
		if(b[id]){
			ans[id].L = last;
			last++;
			ans[id].R = last;
		}
		else{
			if(an.R > last){
				cout << -1 << endl;
				return 0;
			}
			ans[id] = an;
			an.L++;
			if(an.R - an.L == 1){
				an.R++;
				an.L = 1;
			}
		}
	}
	for(int i = 0; i < m; i++)
		cout << ans[i].L << ' ' << ans[i].R << '\n';
	return 0;
}