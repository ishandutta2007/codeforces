#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;
typedef pair<pie, int> piie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69;
int ans[maxn];
vector <piie> all;
queue<int> Q;
int n, A, B;

bool is_in_A(int x){
	int id = lower_bound(all.begin(), all.end(), MP(MP(x, 1), 0)) - all.begin();
	if(id == all.size() or all[id].L.L != x or all[id].L.R != 1)
		return false;
	return true;
}

bool is_in_B(int x){
	int id = lower_bound(all.begin(), all.end(), MP(MP(x, 0), 0)) - all.begin();
	if(id == all.size() or all[id].L.L != x or all[id].L.R != 0)
		return false;
	return true;
}

bool is_OK(int id){
	if(all[id].L.R == 0){
		int id2 = lower_bound(all.begin(), all.end(), MP(MP(B - all[id].L.L, 0), 0)) - all.begin();
		if(id2 == all.size() or all[id].L != MP(B - all[id].L.L, 0))
			return false;
		return true;
	}
	int id2 = lower_bound(all.begin(), all.end(), MP(MP(A - all[id].L.L, 1), 0)) - all.begin();
	if(id2 == all.size() or all[id].L != MP(B - all[id].L.L, 1))
		return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> A >> B;
	for(int i = 1; i <= n; i++){
		int xx;
		cin >> xx;
		all.PB(MP(MP(xx, 1), i));
	}
	sort(all.begin(), all.end());
	for(int i = 0; i < all.size(); i++){
		int id = lower_bound(all.begin(), all.end(), MP(MP(A - all[i].L.L, -1), 0)) - all.begin();
		if(id == all.size() or all[id].L.L != A - all[i].L.L)
			Q.push(i), all[i].L.R = 0;
	}
	while(Q.size()){
		int id;
		piie x = all[Q.front()];
		Q.pop();
		if(is_in_B(B - x.L.L))
			goto checkforA;
		if(!is_in_A(B - x.L.L)){
			cout << "NO" << endl;
			return 0;
		}
		id = lower_bound(all.begin(), all.end(), MP(MP(B - x.L.L, 1), 0)) - all.begin();
		all[id].L.R = 0;
		Q.push(id);
		if(!is_in_A(A - x.L.L))
			continue;
		if(is_OK(id))
			continue;
checkforA:
		id = lower_bound(all.begin(), all.end(), MP(MP(A - x.L.L, 1), 0)) - all.begin();
		while(id < all.size() and all[id].L == MP(A - x.L.L, 1)){
			all[id].L.R = 0;
			Q.push(id);
			id++;
		}
	}
	for(int i = 0; i < all.size(); i++)
		ans[all[i].R] = 1 - all[i].L.R;
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}