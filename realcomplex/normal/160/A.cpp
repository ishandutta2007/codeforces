#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int co[n];
	int sum = 0;
	for(int i = 0;i<n;i++){
		cin >> co[i];
		sum += co[i];
	}
	sort(co,co + n);
		
	int bro = sum;
	int coi = 0;
	for(int i = n - 1;i>=0;i--){
		bro -= co[i];
		coi++;
		if(sum - bro > bro){
			cout << coi;
			break;
		}
	}
	return 0;
}