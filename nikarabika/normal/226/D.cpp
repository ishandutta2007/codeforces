#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 100 + 85 - 69;
int row_sum[maxn];
int col_sum[maxn];
set<pii> s;
int n, m;
int a[maxn][maxn];
vector<int> act_col, act_row;

void fix_row(int r){
	s.erase(MP(row_sum[r], r));
	row_sum[r] *= -1;
	for(int j = 0; j < m; j++){
		s.erase(MP(col_sum[j], n + j));
		col_sum[j] -= 2 * a[r][j];
		s.insert(MP(col_sum[j], n + j));
		a[r][j] *= -1;
	}
	s.insert(MP(row_sum[r], r));
	return;
}

void fix_col(int c){
	s.erase(MP(col_sum[c], n + c));
	col_sum[c] *= -1;
	for(int i = 0; i < n; i++){
		s.erase(MP(row_sum[i], i));
		row_sum[i] -= 2 * a[i][c];
		s.insert(MP(row_sum[i], i));
		a[i][c] *= -1;
	}
	s.insert(MP(col_sum[c], n + c));
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			row_sum[i] += a[i][j];
			col_sum[j] += a[i][j];
		}
	for(int i = 0; i < n; i++)
		s.insert(MP(row_sum[i], i));
	for(int j = 0; j < m; j++)
		s.insert(MP(col_sum[j], n + j));
	while((s.begin()->L) < 0){
		int x = s.begin() -> R;
		if(x >= n){
			fix_col(x - n);
			act_col.PB(x - n);
		}
		else{
			fix_row(x);
			act_row.PB(x);
		}
	}
	sort(act_row.begin(), act_row.end());
	sort(act_col.begin(), act_col.end());
	for(int i = (int)act_row.size() - 2; i >= 0; i--)
		if(act_row[i] == act_row[i + 1])
			act_row.erase(act_row.begin() + i, act_row.begin() + i + 2);
	for(int i = (int)act_col.size() - 2; i >= 0; i--)
		if(act_col[i] == act_col[i + 1])
			act_col.erase(act_col.begin() + i, act_col.begin() + i + 2);
	cout << act_row.size() << ' ';
	for(auto x : act_row)
		cout << x + 1 << ' ';
	cout << endl;
	cout << act_col.size() << ' ';
	for(auto x : act_col)
		cout << x + 1 << ' ';
	cout << endl;
	return 0;
}