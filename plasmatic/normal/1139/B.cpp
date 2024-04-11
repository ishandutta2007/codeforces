//============================================================================
// Name        : 548B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 200001;
int n, last = 0x3f3f3f3f,
	arr[MAX];
ll tot = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = n - 1; i >= 0; --i) {
		int val;
		if(arr[i] > last - 1)
			val = last - 1;
		else
			val = arr[i];

		if(val < 0) val = 0;

		tot += val;
		last = val;
	}

	cout << tot << endl;
}