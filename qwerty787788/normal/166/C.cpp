#include <map>
#include <set>
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype> 
#include <cstdio>
#include <string>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
//
int n, x;
long long t1, t2;
vector <int> a;
//
int main() {
	//freopen("Input.txt", "r", stdin);
	//freopen("Output.txt", "w", stdout);
	//
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		long long y;
		scanf("%d ", &y);
		a.push_back(y);
	}
	sort(a.begin(), a.end());
	long elem = (n+1)/2;
	long add = 0;
	while (a[(a.size() + 1) / 2 - 1] != x) {
		add++;
		a.push_back(x);
		sort(a.begin(), a.end());
	}
	cout << add << endl;
}