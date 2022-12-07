#include <bits/stdc++.h>

using namespace std;

int n;

int ask(string u){
	cout << "? " << u << endl;
	cout.flush();
	int ans = 0;
	cin >> ans;
	return ans;
}


int Bs(char bit, char other){


	string now;
	for(int i = 1; i <= n; ++i){
		now += bit;
	}

	int t = ask(now);

	int low = 1, high = n - 1, ans = n;
	while(low <= high){
		int mid = (low + high) >> 1;
		string curr;
		for(int i = 1; i <= n; ++i){
			if(i < mid){
				curr += other;
			}
			else{
				curr += bit;
			}
		}
		int c = ask(curr);
		int x = (c + t - (mid - 1)) / 2;


		if(x == 0){
			ans = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	return ans - 1;
}

void answer(int x, int y){
	cout << "! " << x << " " << y;
	cout.flush();
	exit(0);
}

int main(){


	cin >> n;

	string curr;

	for(int i = 1; i <= n; ++i){
		curr += '0';
	}

	int t = ask(curr);

	for(int i = 0; i < n - 1; ++i){
		curr[i] = '1';
	}
	int c = ask(curr);

	int k = (c + t - (n - 1)) / 2;


	if(k == 0){
		answer(n, Bs('0', '1'));
	}
	else{
		answer(Bs('1', '0'), n);
	}



	return 0;
}