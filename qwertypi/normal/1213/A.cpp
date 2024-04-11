#include <iostream>

using namespace std;
int cnt[2] = {0, 0};
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		cnt[v % 2]++;
	}
	cout << min(cnt[0], cnt[1]);
}