#include <iostream>

using namespace std;

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int time1 = t1 + v1 * s + t1;
  int time2 = t2 + v2 * s + t2;
  if (time1 < time2) {
    cout << "First" << endl;
  } else if (time1 > time2) {
    cout << "Second" << endl;
  } else {
    cout << "Friendship" << endl;
  }
  return 0;
}