#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	ll temp, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		sum += temp;
	}
	ll ind1, ind2;
	cin >> ind1 >> ind2;
	if (ind1 < ind2) swap(ind1, ind2);
	for (int i = 2; i < n; i++) {
		cin >> temp;
		if (temp > ind1) {
			ind2 = ind1;
			ind1 = temp;
		}
		else
			if (temp > ind2) ind2 = temp;
	}
	if (sum <= ind1 + ind2) cout << "YES";
	else cout << "NO";
	//system("pause");
    return 0;
}