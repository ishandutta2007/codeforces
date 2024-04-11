#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "map"

using namespace std;
const long long int MOD = 1000000007;

char letter[1000];
bool flag[26];
int num;

int main() {
	cin >> letter;
	for (int i = 0; letter[i] != NULL; i++) {
		if(!flag[letter[i]-'a']){
			if (num == letter[i] - 'a') {
				flag[num] = true;
				num++;
				if (num == 26) {
					cout << "YES\n";
					return 0;
				}
			}
			else {
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	return 0;
}