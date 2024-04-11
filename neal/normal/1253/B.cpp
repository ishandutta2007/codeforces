#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int A_MAX = 1e6 + 5;

int N;
vector<int> day(A_MAX, -1);
int day_index = 0;
vector<bool> present(A_MAX, false);
int people = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<int> events;
    int last = -1;

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if (a > 0) {
            if (present[a] || day[a] == day_index) {
                cout << -1 << '\n';
                return 0;
            }

            present[a] = true;
            people++;
            day[a] = day_index;
        } else {
            a = -a;

            if (!present[a] || day[a] != day_index) {
                cout << -1 << '\n';
                return 0;
            }

            present[a] = false;
            people--;

            if (people == 0) {
                events.push_back(i - last);
                last = i;
                day_index++;
            }
        }
    }

    if (people != 0) {
        cout << -1 << '\n';
        return 0;
    }

    if (last < N - 1)
        events.push_back(N - 1 - last);

    cout << events.size() << '\n';

    for (int i = 0; i < (int) events.size(); i++)
        cout << events[i] << (i < (int) events.size() - 1 ? ' ' : '\n');
}