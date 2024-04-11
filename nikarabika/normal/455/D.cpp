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

const int maxn = 1e5 + 85 - 69, maxsq = 320;
deque<int> dq[maxsq];
int arr[maxn][maxsq + 10];
int n;

void add(int row, int idx, int val){
	arr[row][idx] += val;
	return;
}

int get(int row, int st, int en){
	int ret = 0;
	for(int i = st; i <= en; i++)
		ret += arr[row][i];
	return ret;
}

int main(){
	scanf("%d", &n);
	for(int st = 0; st < n; st += maxsq){
		for(int i = st; i < min(st + maxsq, n); i++){
			int x;
			scanf("%d", &x);
			dq[st / maxsq].push_back(x);
			add(x, st / maxsq, +1);
		}
	}
	int q, ans = 0;
	scanf("%d", &q);
	while(q--){
		int ty;
		scanf("%d", &ty);
		if(ty == 1){
			int fi, se;
			scanf("%d%d", &fi, &se);
			fi = ((fi + ans - 1) % n) + 1;
			se = ((se + ans - 1) % n) + 1;
			fi--, se--;
			if(fi > se)
				swap(fi, se);
			int id1 = fi / maxsq, id2 = se / maxsq;
			fi %= maxsq, se %= maxsq;
			int x = dq[id2][se % maxsq];
			dq[id2].erase(dq[id2].begin() + se);
			add(x, id2, -1);
			dq[id1].insert(dq[id1].begin() + fi, x);
			add(x, id1, +1);
			for(int id = id1; id < id2; id++){
				x = dq[id].back();
				dq[id].pop_back();
				add(x, id, -1);
				dq[id + 1].push_front(x);
				add(x, id + 1, +1);
			}
		}
		else{
			int fi, se, th;
			scanf("%d%d%d", &fi, &se, &th);
			fi = ((fi + ans - 1) % n) + 1;
			se = ((se + ans - 1) % n) + 1;
			th = ((th + ans - 1) % n) + 1;
			fi--, se--;
			if(fi > se)
				swap(fi, se);
			int id1 = fi / maxsq, id2 = se / maxsq;
			fi %= maxsq, se %= maxsq;
			ans = 0;
			if(id1 + 1 <= id2 - 1)
				ans = get(th, id1 + 1, id2 - 1);
			if(id1 == id2){
				for(int i = fi; i <= se; i++)
					ans += dq[id1][i] == th;
			}
			else{
				for(int i = fi; i < sz(dq[id1]); i++)
					ans += dq[id1][i] == th;
				for(int i = 0; i <= se; i++)
					ans += dq[id2][i] == th;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}