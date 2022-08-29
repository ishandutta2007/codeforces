#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

long long factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n - 1);
}

long long arrangements(vector<int> counts, bool initial = true) {
    int sum = accumulate(counts.begin(), counts.end(), 0);

    if (sum == 0)
        return 0;

    long long answer = factorial(sum);

    for (int count : counts) {
        answer /= factorial(count);
    }

    if (counts[0] > 0 && initial) {
        counts[0]--;
        answer -= arrangements(counts, false);
        counts[0]++;
    }

    return answer;
}

long long get_count(vector<int> digits, int position = 0) {
    if (position >= (int) digits.size()) {
        return arrangements(digits);
    }

    long long answer = 0;
    int original = digits[position];

    if (original == 0)
        return get_count(digits, position + 1);

    for (int value = 1; value <= original; value++) {
        digits[position] = value;
        answer += get_count(digits, position + 1);
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string number;
    cin >> number;
    vector<int> digits(10, 0);

    for (char c : number)
        digits[c - '0']++;

    cout << get_count(digits) << '\n';
    return 0;
}