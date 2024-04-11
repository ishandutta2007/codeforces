#include <bits/stdc++.h>
using namespace std;

bool checkprime(long long k) {
      if (k == 2) return 1;
      if (k % 2 == 0) return 0;
      for (long long i = 3; i <= sqrt(k); i+=2) {
            if (k % i == 0) return 0;
      }
      return 1;
}

int main() {
      
      long long n;
      cin >> n;
      if (n == 9) {cout << 2 << endl << 2 << " " << 7; return 0;}
      if (n == 4) {cout << 2 << endl << "2 2"; return 0;}
      if (n == 6) {cout << 2 << endl << "3 3"; return 0;}
      if (checkprime(n)) {cout << 1 << endl << n; return 0;}
      if (n % 2) {
            cout << 3 << endl << 3 << " ";
            n -= 3;
      } else {
            cout << 2 << endl;
      }
      long long i = 1;
      n /= 2;
      while (i) {
            if (checkprime(n+i) && checkprime(n-i)) {
                  cout << n+i << " " << n-i; return 0;
            }
            i++;
      }
      
}