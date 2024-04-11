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

const int maxn = 3e4 + 85 - 69;
int mark[maxn];
int a[maxn],
	pos[maxn],
	fm1[maxn];
vector<int> all;
int n, cnt;

void go(int i, int d){
	//cout << i << endl;
	fm1[++cnt] = i;
	mark[i] = cnt;
	//cons[i] = (i == n - 1);
	int id = lower_bound(all(all), a[i] + d) - all.begin();
	if(id == sz(all) or all[id] != a[i] + d or pos[id] < i) return;
	return go(pos[id], d);
	//if(pos[id] == i + 1)
	//	cons[i] = cons[pos[id]];
	//return;
}

bool go2(int i, int d, int cnt = 1){
	//cout << " " << i << endl;
	if(cnt + ::cnt == n)
		return true;
	mark[i] = 0;
	int id = lower_bound(all(all), a[i] + d) - all.begin();
	if(id == sz(all) or all[id] != a[i] + d or pos[id] > i) return false;
	if(!mark[pos[id]]) return go2(pos[id], d, cnt + 1);
	return false;
}

bool go3(int i, int d, int cnt = 1){
	//cout << "  " << i << endl;
	if(cnt + ::cnt == n)
		return true;
	int id = lower_bound(all(all), a[i] + d) - all.begin();
	if(id == sz(all) or all[id] != a[i] + d or pos[id] > i) return false;
	if(mark[pos[id]]){
		if(mark[pos[id]] != ::cnt) return false;
		::cnt--;
	}
	mark[pos[id]] = 0;
	return go3(pos[id], d, cnt + 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	if(n == 2){
		cout << a[0] << endl
			<< a[1] << endl;
		return 0;
	}
	sort(all(all));
	for(int i = 0; i < n; i++)
		pos[lower_bound(all(all), a[i]) - all.begin()] = i;
	for(int i = 0; i < 3; i++)
		for(int j = i + 1; j < 3; j++){
			memset(mark, 0, sizeof mark);
			cnt = 0;
			go(i, a[j] - a[i]);
			int id1 = -1,
				id2 = -1;
			for(int k = n - 1; k >= 0; k--)
				if(!mark[k]){
					if(id1 == -1) id1 = k;
					else if(id2 == -1) id2 = k;
				}
			if(id1 == -1){
				cout << a[0] << '\n';
				for(int i = 1; i < n; i++)
					cout << a[i] << " \n"[i == n - 1];
				return 0;
			}
			if(id2 == -1){
				cout << a[id1] << '\n';
				for(int i = 0; i < n; i++)
					if(i != id1)
						cout << a[i] << " ";
				cout << '\n';
				return 0;
			}
			if(go2(id1, a[id2] - a[id1])){
				for(int k = 0; k < n; k++)
					if(mark[k])
						cout << a[k] << ' ';
				cout << '\n';
				for(int k = 0; k < n; k++)
					if(!mark[k])
						cout << a[k] << ' ';
				cout << '\n';
				return 0;
			}
			do{
				mark[fm1[::cnt]] = 0;
			}while(::cnt and fm1[::cnt] > id1);
			id1 = id2 = -1;
			for(int k = n - 1; k >= 0; k--)
				if(!mark[k]){
					if(id1 == -1) id1 = k;
					else if(id2 == -1) id2 = k;
				}
			if(go3(id1, a[id2] - a[id1])){
				for(int k = 0; k < n; k++)
					if(mark[k])
						cout << a[k] << ' ';
				cout << '\n';
				for(int k = 0; k < n; k++)
					if(!mark[k])
						cout << a[k] << ' ';
				cout << '\n';
				return 0;
			}
		}
	cout << "No solution\n";
	return 0;
}