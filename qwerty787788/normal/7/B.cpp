#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;
//
long long t, n;
long long mem[100];
string s;
//
int main() {
        //freopen("input.txt", "r", stdin);
        ///freopen("output.txt", "w", stdout);
        //
		cin >> t >> n;
		long long su = 0;
		for (int op = 0; op < t; op++) {
			cin >> s;
			if (s == "alloc") {
				long long N;
				cin >> N;
				bool ok = false;
				for (int i = 0; i < n - N +1; i++) {
					bool ok1 = true;
					for (int j = i; j < i + N; j++)
						if (mem[j] != 0) ok1 = false;
					if (ok1) { 
						su++;
						for (int j = i; j < i + N; j++)
							mem[j] = su;
						ok = true;
						break;
					}
				}
				if (ok) cout << su << endl; else 
						cout << "NULL" << endl;
			}
			if (s == "erase") {
				long long N;
				cin >> N;
				bool ok = false;
				for (int i = 0; i < n; i++)
					if (mem[i] == N) {
						mem[i] = 0;
						ok = true;
					}
				if (!ok || N==0) cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
			}
			if (s == "defragment") {
				for (int i = 0; i < n; i++) {
					if (mem[i] == 0) 
						for (int j = i+1; j< n; j++)
							if (mem[j] != 0) {
								mem[i] = mem[j];
								mem[j] = 0;
								break;
							}
				}
			}
		}
}