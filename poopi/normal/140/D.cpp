										/* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
int tm[110];

int main(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> tm[i];
	sort(tm, tm + n);
	int pr = 0;
	int tot = 0, sum = 0;
	for(int i = 0; i < n; i++){
		if(tot + tm[i] <= 710){
			tot += tm[i];
			pr++;
			sum += max(0, tot - 350);
		}
	}
	cout << pr << ' ' << sum << endl;
	return 0;
}