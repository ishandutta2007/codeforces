#include <vector>
#include <iostream>

using namespace std;
vector<int> A;
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	char prev = ' ';
	int cnt = 0;
	for(auto i : s){
		if(i == prev){
			cnt++;
		}else{
			if(prev != ' '){
				A.emplace_back(cnt);
			}
			cnt = 1;
		}
		prev = i;
	}
	A.emplace_back(cnt);
	long long ans = (long long) n * (n - 1) / 2;
	for(int i = 0; i < (int)A.size() - 1; i++){
		ans -= A[i] + A[i + 1] - 1;
	}
	cout << ans;
}