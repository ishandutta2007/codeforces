#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 100;
int a[maxn], b[maxn], rec[maxn], n;
set<pie> s;
string f[maxn];
vector<int> ans;
bool mark[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> f[i];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
		s.insert(MP(a[i], i));
	}
	while(s.size() and s.begin()->L == 0){
		int x = s.begin()->R;
		ans.PB(x);
		s.erase(s.begin());
		for(int i = 0; i < n; i++)
			if(!mark[i] and f[x][i] - '0'){
				rec[i]++;
				s.erase(MP(a[i], i));
				a[i]--;
				if(a[i] >= 0)
					s.insert(MP(a[i], i));
			}
		mark[x] = true;
	}
	for(int i = 0; i < n; i++)
		if(rec[i] == b[i]){
			cout << -1 << endl;
			return 0;
		}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] + 1 << ' ';
	cout << endl;
	return 0;
}