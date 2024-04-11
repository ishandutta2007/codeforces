#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

//
string s;
int n;
//
vector <int> a[1000];
//
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//
	cin >> n;
	int x = 0;
	while (x*(x-1) <= 2*n) x++;
	x--;
	int z = 1;
	for (int i = 1; i < x; i++)
		for (int j = i+1; j <= x; j++) {
			a[i].push_back(z);
			a[j].push_back(z);
			z++;
		}
	//
	cout << x << endl;
	for (int i = 1; i <= x; i++) {
		for (int j =0 ; j < a[i].size(); j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	//
	return 0;
}