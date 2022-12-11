#include <iostream>

using namespace std;

const int N = 60;

int data[N];
long long C[N];
long long k;
int n;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  C[0] = C[1] = 1ll;
  for(int i = 2;i <= n;i++) {
    C[i] = C[i-1] + C[i-2]; 
  }
  for(int i = 1;i <= n;i++) {
    data[i] = i;
  }
  for(int i = 1;i <= n;) {
    if(k <= C[n-i]) {
      cout << i << " ";
      i++;
    }else {
      k -= C[n-i];
      cout << i+1 << " " << i << " ";
      i += 2;
    }
  }
  cout << endl;
  return 0;
}