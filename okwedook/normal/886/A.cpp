#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>
#include <map>
#include <algorithm>
#include <string>
#include <iomanip>
 
using namespace std;
 
int main() {
	vector<int> arr(6);
	for (int &i : arr) cin >> i;
	int sum = 0;
	for (int i : arr) sum += i;
	if (sum % 2 == 1) {
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < 6; i++)
		for (int j = i + 1; j < 6; j++)
			for (int k = j + 1; k < 6; k++)
				if (arr[i] + arr[j] + arr[k] == sum / 2) {
					cout << "YES";
					return 0;
				}
	cout << "NO";
    return 0;
}