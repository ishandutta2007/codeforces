#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int a[100000];
bool start[100000];
int x, y;
int t = 0;
//
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n ; i++)
		cin >> a[i];
	//
	x = 0;
	y = n-1;
	while (x < y) {
		t=min(a[x], a[y]);
		a[x]-=t;
		a[y]-=t;
		start[y] = true;
		if (a[x]==0) x++;
		if (a[y]==0) y--;
	}
	//
	if (x>y) {
		cout << x << " " << (n-y-1) << endl;
	} else {
		if (start[x]) cout << x << " " << (n-y) << endl; else
					  cout << (x+1) << " " << (n-y-1) << endl;
	}
	//
	return 0;
}