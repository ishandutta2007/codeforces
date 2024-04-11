#include <iostream>
using namespace std;

int A[100001] = {}, d;
int t[4];

int main(){
	for (int i = 0; i < 4; i++) cin >> t[i];
	cin >> d;
	for (int i = 0; i < 4; i++)
		for (int j = t[i]; j <= d; j += t[i])
			A[j] = 1;
	int answer = 0;
	for (int i = 1; i <= d; i++)
		if (A[i]) answer++;
	cout << answer;
}