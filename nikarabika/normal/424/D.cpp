//sobskdrbhvk
//remember the flying, the bird dies ):(
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

const int maxn = 300 + 10;
set<pii> s;
int a[maxn][maxn],
	doval[maxn][maxn],
	upval[maxn][maxn],
	leval[maxn][maxn],
	rival[maxn][maxn],
	n, m, t,
	tu, tp, td;

#define gol(r, cl, cr) (leval[r][cr] - leval[r][cl])
#define gor(r, cl, cr) (rival[r][cr] - rival[r][cl])
#define gou(i, j) upval[i][j]
#define god(i, j) doval[i][j]

#define func(x, y) (x < y ? tu : x == y ? tp : td)
#define dif(x) (x < t ? t - x : x - t)

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans = 1000 * 1000 * 1000 * 2;
	int ansiu = -1, ansid = -1,
		ansjl = -1, ansjr = -1;
	cin >> n >> m >> t
		>> tp >> tu >> td;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i){
				doval[i][j] = doval[i - 1][j] + func(a[i - 1][j], a[i][j]);
				upval[i][j] = upval[i - 1][j] + func(a[i][j], a[i - 1][j]);
			}
			if(j){
				leval[i][j] = leval[i][j - 1] + func(a[i][j], a[i][j - 1]);
				rival[i][j] = rival[i][j - 1] + func(a[i][j - 1], a[i][j]);
			}
		}
	}
	for(int jl = 0; jl < m; jl++){
		for(int jr = jl + 2; jr < m; jr++){
			s.clear();
			pii tmp = MP(-1, -1);
			for(int i = n - 1; i >= 0; i--){
				if(i < n - 2){
					int curval = gor(i, jl, jr) - gou(i, jl) - god(i, jr);
					auto it = s.lower_bound(MP(t - curval, -1));
					if(it != s.end()){
						int val = curval + it->L;
						if(dif(val) < ans){
							ans = dif(val);
							//cout << val << ' ' << i << ' ' << it->R << ' ' << jl << ' ' << jr << '\n';
							ansjl = jl;
							ansjr = jr;
							ansiu = i;
							ansid = it->R;
						}
					}
					if(it != s.begin()){
						it--;
						int val = curval + it->L;
						if(dif(val) < ans){
							ans = dif(val);
							//cout << val << ' ' << i << ' ' << it->R << ' ' << jl << ' ' << jr << '\n';
							ansjl = jl;
							ansjr = jr;
							ansiu = i;
							ansid = it->R;
						}
					}
				}
				if(tmp.R != -1) s.insert(tmp);
				tmp = MP(gol(i, jl, jr) + gou(i, jl) + god(i, jr), i);
			}
			/*if(jl == 2 and jr == 6){
				for(auto P : s)
					cout << P.L << ':' << P.R << ' ';
				cout << endl;
			}*/
		}
	}
	cout << ansiu+1  << ' ' << ansjl+1 << ' ' << ansid+1 << ' ' << ansjr+1 << '\n';
	//int val = 0;
	/*ansiu = 3, ansid = 5;
	ansjl = 2, ansjr = 6;*/
	/*for(int j = ansjl + 1; j <= ansjr; j++)
		val += func(a[ansiu][j - 1], a[ansiu][j]) + func(a[ansid][j], a[ansid][j - 1]);
	for(int i = ansiu + 1; i <= ansid; i++)
		val += func(a[i - 1][ansjr], a[i][ansjr]) + func(a[i][ansjl], a[i - 1][ansjl]);
	cout << val << endl;
	cout << gor(ansiu, ansjl, ansjr) + gol(ansid, ansjl, ansjr) + gou(ansid, ansjl) - gou(ansiu, ansjl) + god(ansid, ansjr) - god(ansiu, ansjr) << endl;*/
	return 0;
}