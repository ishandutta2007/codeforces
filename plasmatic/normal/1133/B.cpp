//============================================================================
// Name        : 544B.cpp
// Author      : Daxi the Taxi
// Version     :
// Copyright   : ALL YOUR CODE IS BELONG TO US
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> p;

const int MK = 101;
int n, k, buf, tot = 0,
	freq[MK];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; ++i) {
		cin >> buf;
		freq[buf % k]++;
	}

	tot = freq[0] - (freq[0] % 2);

	if(k % 2 == 0){
		int half = k >> 1;
		tot += freq[half] - (freq[half] % 2);
	}

	int half = (k >> 1) - (k % 2 == 0);
	for (int i = 0; i <= half; ++i)
		tot += min(freq[i], freq[k - i]) << 1;

	printf("%d\n", tot);
}