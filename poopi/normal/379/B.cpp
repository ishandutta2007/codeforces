						/* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

#define P pair<int, int>

int n;
int v[310];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < v[i]; j++)
			cout << 'P' << (i == 0 ? "RL" : "LR");
		if(i != n - 1)
			cout << 'R';
	}
	cout << endl;
	return 0;
}