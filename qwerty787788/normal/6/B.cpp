#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
char c;
char a[100][100];
int an[26];
int answ = 0;
//
void add(int i, int j) {
	if ((i>=0)&&(j>=0)&&(i<n)&&(j<m)) {
		if ((a[i][j] != '.')&&(a[i][j]!=c))
			if (an[a[i][j]-'A']==0) an[a[i][j]-'A'] = 1;
	}
}
//
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> n >> m >> c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];	
		}
	//
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == c) {
				add(i-1, j);
				add(i+1, j);
				add(i, j-1);
				add(i, j+1);
			}
	//
	for (int i = 0; i < 26; i++)
		if (an[i] > 0) answ++;
	cout << answ << endl;
	//
	return 0;
}