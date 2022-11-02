#include <bits/stdc++.h>

using namespace std;
int A[400000];
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> p;
		int cnt = 0;
		int prev = 0;
		for(int i = 0; i < n; i++){
			int v;
			cin >> v;
			A[i] = v;
			if(i < n / 2){
				if(v == prev){
					cnt++;
				}else{
					if(cnt != 0){
						p.push_back(cnt);
					}
					cnt = 1;
				}
				prev = v;
			}
		}
		if(cnt != 0 && A[n / 2] != A[n / 2 - 1]){
			p.push_back(cnt);
			cnt = 0;
		}
		if(p.size() < 3){
			cout << 0 << ' ' << 0 << ' ' << 0 << endl;
			continue;
		}
		int gold = p[0];
		int silver = 0;
		int curPos = 1;
		while(silver <= gold && curPos < p.size()){
			silver += p[curPos++];
		}
		int bronze = accumulate(p.begin(), p.end(), 0) - gold - silver;
		if(gold < bronze && gold < silver){
			cout << gold << ' ' << silver << ' ' << bronze << endl;
		}else{
			cout << 0 << ' ' << 0 << ' ' << 0 << endl;
		}
	}
}