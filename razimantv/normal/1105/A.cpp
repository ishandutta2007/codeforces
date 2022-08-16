#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int calculate_cost(vector<int> &A, int t) {
  int cost = 0;

  for (int i = 0; i < A.size(); i++) {
    if (A[i] < t)
      cost += ((t - 1) - A[i]);
    if (A[i] > t)
      cost += (A[i] - (t + 1));
  }

  return cost;
}

int main() {
  int no_of_elements;
  cin >> no_of_elements;

  vector<int> A(no_of_elements);
  for (int i = 0; i < no_of_elements; i++)
    cin >> A[i];

  const int MAX = 100;
  int left = 1, right = MAX;

  while (left < right) {
    int mid_1 = (2 * left + right) / 3;
    int mid_2 = (left + 2 * right) / 3; // cout << "L = " << left << " R = " <<
                                        // right << " m1 = " << mid_1 << " m2 =
                                        // " << mid_2 << endl;

    if (calculate_cost(A, mid_1) <= calculate_cost(A, mid_2)) {
      right = mid_2;
    } else {
      left = mid_1 + 1;
    }
  }

  int answer =
      (calculate_cost(A, left) < calculate_cost(A, right) ? left : right);

  cout << answer << " " << calculate_cost(A, answer);

  return 0;
}