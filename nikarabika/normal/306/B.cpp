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

const int maxn = 200 * 1000 + 85 - 69;
int order[maxn],
	l[maxn],
	r[maxn],
	nxt[maxn * 10],
	n, m;
bool mark[maxn];
vector<int> ans;

bool cmp(int i, int j){return l[i] < l[j];}
int Next(int pos){return nxt[pos] == pos ? pos : nxt[pos] = Next(nxt[pos]);}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i <= n + 1; i++)
		nxt[i] = i;
	for(int i = 0; i < m; i++){
		cin >> l[i] >> r[i];
		r[i] += l[i];
		order[i] = i;
		for(int pos = l[i]; pos < r[i]; pos = Next(pos))
			nxt[pos] = pos + 1;
	}
	sort(order, order + m, cmp);
	int pos = 1, p = 0;
	while(pos <= n){
		if(nxt[pos] == pos){
			pos++;
			continue;
		}
		int maxid = -1;
		while(p < m and l[order[p]] <= pos){
			if(maxid == -1 or r[order[p]] > r[maxid])
				maxid = order[p];
			p++;
		}
		mark[maxid] = true;
		pos = r[maxid];
	}
	for(int i = 0; i < m; i++)
		if(!mark[i])
			ans.PB(i + 1);
	cout << sz(ans) << '\n';
	for(auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}