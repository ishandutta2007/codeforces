#include "iostream"
#include "stdio.h"
#include "iomanip"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "string"
#include "utility"

using namespace std;

int N;
char letter[200000];
int num[10];
int ans = 100000;

int main() {
	cin >> letter;
	for (int i = 0; letter[i] != NULL; i++) {
		if (letter[i] == 'B')num[0]++;
		if (letter[i] == 'u')num[1]++;
		if (letter[i] == 'l')num[2]++;
		if (letter[i] == 'b')num[3]++;
		if (letter[i] == 'a')num[4]++;
		if (letter[i] == 's')num[5]++;
		if (letter[i] == 'r')num[6]++;
	}
	for (int i = 0; i < 7; i++) {
		ans = min(ans, num[i]);
	}
	ans = min(ans, num[4] / 2);
	ans = min(ans, num[1] / 2);
	cout << ans << endl;
	return 0;
}

//Bulbasaur