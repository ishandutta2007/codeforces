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
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

char S[1000];
bool start[1000];
bool flag;
int ans;

int main(){
	cin >> S;
	for (int i = 0; S[i + 1] != NULL; i++) {
		if (S[i] == 'V'&&S[i + 1] == 'K') {
			ans++;
			start[i] = true;
			start[i + 1] = true;
			i++;
		}
	}
	for (int i = 0; S[i + 1] != NULL; i++) {
		if (start[i]||start[i+1])continue;
		if (S[i] == S[i + 1] && (S[i] == 'V' || S[i] == 'K'))flag = true;
	}
	cout << ans + flag << endl;
}