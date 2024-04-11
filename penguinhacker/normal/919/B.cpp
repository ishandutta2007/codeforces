#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int sumDig (int x) {
    int s = 0;
    while (x != 0) {
      s = s + x % 10;
      x = x / 10;
   }
   return s;
}

int main() {
	int n;
	cin >> n;
    n--;
    int k[10000];
    int num = 18;
    for (int i=0; i<10000; ++i) {
        while (sumDig(num) != 10) num++;
        k[i] = num;
        num++;
    }

    cout << k[n] << '\n';
	return 0;
}