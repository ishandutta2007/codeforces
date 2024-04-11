#include <bits/stdc++.h>
#define inf (1 << 30)
using namespace std;

int A[200001];
int min2[2], max2[2];
void init(){
	min2[0] = min2[1] = inf;
	max2[0] = max2[1] = -inf;
}

void upd(int x){
	if(x < min2[0]) min2[0] = x;
	else if(x < min2[1]) min2[1] = x;

	if(x > max2[0]) max2[0] = x;
	else if(x > max2[1]) max2[1] = x;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 0; i < n; i++) cin >> A[i];
		int ans = 0;
		for(int i = 0; i < n; i++){
			int R = i - 1;
			init();
			while(R < n - 1 && min2[1] > A[R + 1] && max2[1] < A[R + 1]){
				upd(A[R + 1]);
				R++;
			}
			ans += R - i + 1;
		}
		cout << ans << endl;
	}
}