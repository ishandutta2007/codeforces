#include <bits/stdc++.h>
 
using namespace std;
 
int A[200001];
int SL[200001], SR[200001];
int LL[200001], LR[200001];
vector<pair<int, int>> vii;
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	SL[0] = 0;
	for(int i = 1; i < n; i++){
		SL[i] = (A[i] > A[i - 1] ? SL[i - 1] + 1 : 0);
	}
	LL[0] = 0;
	for(int i = 1; i < n; i++){
		LL[i] = (A[i] < A[i - 1] ? LL[i - 1] + 1 : 0);
	}
	SR[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--){
		SR[i] = (A[i] > A[i + 1] ? SR[i + 1] + 1 : 0);
	}
	LR[n - 1] = 0;
	for(int i = n - 2; i >= 0; i--){
		LR[i] = (A[i] < A[i + 1] ? LR[i + 1] + 1 : 0);
	}
	// lmao I misread the question
	int mx = 0; vector<pair<int, int>> ps;
	for(int i = 0; i < n; i++){
		if(LL[i] > mx){
			ps.clear();
			mx = LL[i];
			ps.push_back({LL[i], i - LL[i]});
		}else if(LL[i] == mx){
			ps.push_back({LL[i], i - LL[i]});
		}
		if(LR[i] > mx){
			ps.clear();
			mx = LR[i];
			ps.push_back({LR[i], i + LR[i]});
		}else if(LR[i] == mx){
			ps.push_back({LR[i], i + LR[i]});
		}
	}
	
	sort(ps.begin(), ps.end());
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i == 0 || i == n - 1) continue;
		if(i != 0 && i != n - 1) if(A[i] < A[i - 1] || A[i] < A[i + 1]) continue;
		if(SL[i] - (SL[i] % 2 == 0) >= SR[i] || SR[i] - (SR[i] % 2 == 0) >= SL[i]) continue;
		// L[i] mod 2 = 0, R[i] mod 2 = 0, L[i] = R[i]
		if(mx > SL[i]) continue;
		bool fail = false;
		for(int j = 0; j < ps.size() && j < 10; j++){
			// cout << ps[j].first << ' ' << ps[j].second << ' ' << i << endl;
			if(ps[j].second != i) fail = true;
		}
		if(!fail) ans++;
	}
	cout << ans << endl;
}