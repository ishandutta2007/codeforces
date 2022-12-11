#include <iostream>

using namespace std;

int arr[] = {0, 52, 52, 52, 52, 53, 53, 52};
int n;
string a, b;

int main() {
  cin >> n >> a >> b;
  if(b == "week") {
    cout << arr[n] << endl;
  }else {
    if(n <= 29) cout << 12 << endl;
    else if(n <= 30) cout << 11 << endl;
    else cout << 7 << endl;
  }
}