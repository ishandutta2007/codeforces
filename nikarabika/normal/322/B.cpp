#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int Max = 0;
	for(int i = max(a[0] - 3, 0); i <= a[0]; i++)
		Max = max(Max, i + (a[0] - i) / 3 + (a[1] - i) / 3 + (a[2] - i) / 3);
	cout << Max << endl;
	return 0;
}