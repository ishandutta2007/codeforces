#include <bits/stdc++.h>

using namespace std;

#define PB push_back

const int maxn = 1e5;
vector<int> v[maxn], bv[maxn];
int a[maxn], n, k;

int numb(string s){
	int ans = 0;
	for(int i = s[0] == '-'; i < s.size(); i++)
		ans = ans * 10 + s[i] - '0';
	if(s[0] == '-')
		ans *= -1;
	return ans;
}

void solve(int x){
	for(int i = 0; i < v[x].size() - 1; i++)
		if(v[x][i] >= v[x][i + 1] - bv[x][i]){
			cout << "Incorrect sequence" << endl;
			exit(0);
		}
	vector<int> ans;
	int id = upper_bound(v[x].begin(), v[x].end(), 0) - v[x].begin() - 1;
	for(int i = 0; i < id; i++){
		ans.PB(v[x][i]);
		for(int j = bv[x][i]; j > 0; j--)
			ans.PB(v[x][i + 1] - j);
	}
	if(v[x][id] != 0){
		ans.PB(v[x][id]);
		int c = bv[x][id];
		if(c == 0){
			id++;
			goto out;
		}
		int st = -(c / 2);
		int en = +((c - 1) / 2);
		int shif = 0;
		while(en - shif >= v[x][id + 1])
			shif++;
		while(st - shif <= v[x][id])
			shif--;
		for(int i = st - shif; i <= en - shif; i++)
			ans.PB(i);
		id++;
	}
out:
	for(int i = id; i < v[x].size(); i++)
		for(int j = 0; j <= bv[x][i]; j++)
			ans.PB(v[x][i] + j);
	v[x] = ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < k; i++)
		v[i].PB(-2e9), bv[i].PB(0);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s == "?")
			bv[i % k].back()++;
		else{
			bv[i % k].PB(0);
			v[i % k].PB(numb(s));
		}
	}
	for(int i = 0; i < k; i++)
		v[i].PB(2e9), bv[i].PB(0);
	for(int i = 0; i < k; i++)
		solve(i);
	for(int i = k; i < n + k; i++)
		cout << v[i % k][i / k] << ' ';
	cout << endl;
	return 0;
}