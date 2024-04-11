#include <iostream>
using namespace std;

int cnt[105];

int main() {
	
	int k;
	int s = 0;
	for(int j = 0;j<5;j++){
		cin >> k;
		s += k;
		cnt[k]++;
	}
	int rez = s;
	for(int j = 0;j<105;j++){
		if(cnt[j] == 2){
			rez = min(rez,s-(cnt[j]*j));
		}
		else if(cnt[j] >= 3){
			rez = min(rez,s-(j*3));
		}
	}
	cout << rez;
	return 0;
}