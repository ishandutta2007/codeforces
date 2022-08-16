// Trying to fix Saikat's code
#include <algorithm>
#include <iostream>
#include <vector>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct element {
  int value, original_position, part_number;

  element() { value = 0; };

  int operator<(const element &E) { return (value < E.value); }
};

int main() {
  int number_of_elements;
  cin >> number_of_elements;

  vector<element> A(number_of_elements + 1);
  for (int i = 1; i <= number_of_elements; i++) {
    int x;
    cin >> x;

    A[i].value = x;
    A[i].original_position = i;
  }

  sort(all(A));

  if (number_of_elements <= 5) {
    cout << A[number_of_elements].value - A[1].value << " 1\n";

    for (int i = 1; i <= number_of_elements; i++) {
      cout << "1 ";
    }

    return 0;
  }

  vector<long long> answer(number_of_elements + 1);

  const long long oo = 1e18;
  vector<long long> best_suffix(number_of_elements + 1, oo);
  for (int i = 1; i <= number_of_elements; i++) {
    if (i >= 3) {
      answer[i] = A[i].value + best_suffix[i - 2];
    } else {
      answer[i] = oo;

      best_suffix[i] = -A[1].value;
    }

    //std::cout << best_suffix[i] << " " << answer[i] << "\n";
    best_suffix[i] = min(best_suffix[i - 1], -A[i].value + answer[i - 1]);
    // cout << A[i].value << " Answer " << i << " = " << answer[i] << " and best
    // suffix = " << best_suffix[i] << "\n";
  }

  int last = number_of_elements, sum = answer[number_of_elements];
  A[number_of_elements].part_number = 1;
  for (int i = number_of_elements - 1; i >= 1; i--) {
    if (A[last].value - A[i + 1].value + answer[i] == sum &&
        (last - i >= 3 && i >= 3)) {
      A[i].part_number = A[last].part_number + 1;

      sum -= (A[last].value - A[i + 1].value);

      last = i;
    } else {
      A[i].part_number = A[last].part_number;
    }
  }

  vector<int> part_alloted(number_of_elements + 1);
  for (int i = 1; i <= number_of_elements; i++) {
    part_alloted[A[i].original_position] = A[i].part_number;
  }

  cout << answer[number_of_elements] << " " << A[1].part_number << "\n";
  for (int i = 1; i <= number_of_elements; i++) {
    cout << part_alloted[i] << " ";
  }

  return 0;
}