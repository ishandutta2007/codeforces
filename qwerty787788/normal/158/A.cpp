#include <map>
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
int n, k;
int a[50];
//
int main() {
    //freopen("Input.txt", "r", stdin);
    //freopen("Output.txt", "w", stdout);
    //
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int pr = a[k - 1];
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (a[i] > 0 && a[i] >= pr) sum++;
	cout << sum << endl;
}