#include <bits/stdc++.h>
 
using namespace std;
 
int A[100001];
int s_a[100001];
int a[100001], b[100001], c[100001];
void solve(){
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	string sp, tp;
	vector<int> sv, tv;
	for(auto i : s) if(i != 'b') sp.push_back(i);
	for(auto i : t) if(i != 'b') tp.push_back(i);
	for(int i = 0; i < n; i++) if(s[i] != 'b') sv.push_back(i);
	for(int i = 0; i < n; i++) if(t[i] != 'b') tv.push_back(i);
	if(sp != tp){
		cout << "NO" << endl;
		return;
	}
	for(int i = 0; i < sp.size(); i++){
		if(sp[i] == 'a' && sv[i] > tv[i] || sp[i] == 'c' && sv[i] < tv[i]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}