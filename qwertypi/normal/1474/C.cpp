#include <bits/stdc++.h>

using namespace std;

int A[2001];
bool chosen[2001];
int main(){
	int t;
	cin >> t;
	for(int iter = 0; iter < t; iter++){
		int n; cin >> n;
		for(int i = 0; i < n * 2; i++){
			cin >> A[i];
		}
		sort(A, A + n * 2);
		int ok = -1;
		for(int j = n * 2 - 2; j >= 0; j--){
			priority_queue<int> pq;
			fill(chosen, chosen + n * 2, false);
			int v = A[n * 2 - 1] + A[j];
			int cnt = 0;
			for(int k = n * 2 - 1; k >= 0; k--){
				if(pq.size() && pq.top() == A[k]) chosen[k] = true, pq.pop();
				if(chosen[k]) continue;
				chosen[k] = true;
				pq.push(v - A[k]);
				v = A[k];
				cnt++;
			}
			if(cnt == n){
				ok = j;
			}
		}
		if(ok == -1){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
			int r = A[n * 2 - 1] + A[ok];
			cout << r << endl;
			priority_queue<int> pq;
			fill(chosen, chosen + n * 2, false);
			int v = r;
			for(int k = n * 2 - 1; k >= 0; k--){
				if(pq.size() && pq.top() == A[k]) chosen[k] = true, pq.pop();
				if(chosen[k]) continue;
				chosen[k] = true;
				cout << A[k] << ' ' << v - A[k] << endl;
				pq.push(v - A[k]);
				v = A[k];
			}
		}
	}
}