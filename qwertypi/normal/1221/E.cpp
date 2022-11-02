#include <iostream>
#include <algorithm>
#include <vector>
// Never retreat
using namespace std;
typedef long long ll;
 
void Solve(){
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	vector<int> A;
	int curCnt = 0;
	for(auto i:s){
		if(i == 'X' && curCnt != 0){
			A.emplace_back(curCnt);
			curCnt = 0;
		}else if(i == '.'){
			curCnt++;
		}
	}
	if(curCnt != 0){
		A.emplace_back(curCnt);
	}
	sort(A.begin(), A.end());
	
	bool OK = true;
	int pred = 0;
	int Magic = 0;
	int cnt = 0;
	for(int i=0;i<A.size();i++){
		if(A[i] < b){
			continue;
		}else if(b <= A[i] && A[i] < a){
			OK = false;
		}else if(A[i] < 2 * b){
		    cnt++;
		}else if(A[i] < a + 4 * b - 1){
			pred++;
			Magic = A[i];
		}else{
			OK = false;
		}
	}
	if(!OK || (pred > 1)){
		cout << "NO" << endl;
	}else{
		if(!pred){
			if(cnt % 2){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}else{
			int t = Magic - a;
			bool f_0 = t <= (b - 1) * 2;
			bool f_1 = 0;
			if(a <= 2 * b - 1){
				f_1 = t >= a && t <= 3 * b - 2;
			}
			bool f_2 = t / 2 >= a;
			if((f_0 || f_2) && (cnt % 2 == 0)){
				cout << "YES" << endl;
			}else if(f_1 && (cnt % 2)){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		Solve();
	}
}