#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int gb;
	cin >> gb;
	int sk[n];
	for(int x = 0;x<n;x++){
		cin >> sk[x];
	}
	int reize = 0;
	sort(sk,sk + n);
	for(int y = n - 1;y>=0;y--){
		gb -= sk[y];
		reize++;
		if(gb <= 0){
			cout << reize;
			break;
		}
	}
	return 0;
}