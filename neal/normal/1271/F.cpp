#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << "\"" << *vi << "\""; } os << "}"; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):"; dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int capacity[2][3];
int D[8];

void intersect(int &start, int &end, int other_start, int other_end) {
    start = max(start, other_start);
    end = min(end, other_end);
}

void run_case() {
    for (int group = 0; group < 2; group++)
        for (int subject = 0; subject < 3; subject++)
            cin >> capacity[group][subject];

    cin >> D[7] >> D[3] >> D[5] >> D[1] >> D[6] >> D[2] >> D[4];

    for (int subject = 0; subject < 3; subject++) {
        int sum = 0;

        for (int mask = 0; mask < 8; mask++)
            if (mask >> subject & 1)
                sum += D[mask];

        if (sum > capacity[0][subject] + capacity[1][subject]) {
            cout << -1 << '\n';
            return;
        }
    }

    int two_or_more = D[7] + D[3] + D[5] + D[6];
    dbg(two_or_more);

    int axy_low = D[7] + D[3] + D[5] - capacity[1][0];
    int axy_high = capacity[0][0];
    dbg(axy_low, axy_high);

    int axz_low = D[7] + D[3] + D[6] - capacity[1][1];
    int axz_high = capacity[0][1];
    dbg(axz_low, axz_high);

    int ayz_low = D[7] + D[5] + D[6] - capacity[1][2];
    int ayz_high = capacity[0][2];
    dbg(ayz_low, ayz_high);

    int a_answer = -1, x_answer = -1, y_answer = -1, z_answer = -1;

    for (int sum = 0; sum <= two_or_more; sum++) {
        int z_low = sum - axy_high, z_high = sum - axy_low;
        int y_low = sum - axz_high, y_high = sum - axz_low;
        int x_low = sum - ayz_high, x_high = sum - ayz_low;

        intersect(x_low, x_high, 0, D[3]);
        intersect(y_low, y_high, 0, D[5]);
        intersect(z_low, z_high, 0, D[6]);

        int a_low = sum - (x_high + y_high + z_high);
        int a_high = sum - (x_low + y_low + z_low);
        intersect(a_low, a_high, 0, D[7]);

        if (a_low <= a_high && x_low <= x_high && y_low <= y_high && z_low <= z_high) {
            a_answer = a_low;
            int xyz_sum = sum - a_answer;
            x_answer = x_low;
            y_answer = y_low;
            z_answer = z_low;
            int current_sum = x_answer + y_answer + z_answer;

            if (current_sum < xyz_sum) {
                int take = min(xyz_sum - current_sum, x_high - x_answer);
                x_answer += take;
                current_sum += take;
            }

            if (current_sum < xyz_sum) {
                int take = min(xyz_sum - current_sum, y_high - y_answer);
                y_answer += take;
                current_sum += take;
            }

            if (current_sum < xyz_sum) {
                int take = min(xyz_sum - current_sum, z_high - z_answer);
                z_answer += take;
                current_sum += take;
            }

            assert(current_sum == xyz_sum);
            break;
        }
    }

    if (a_answer < 0) {
        cout << -1 << '\n';
        return;
    }

    int remaining0 = capacity[0][0] - a_answer - x_answer - y_answer;
    int remaining1 = capacity[0][1] - a_answer - x_answer - z_answer;
    int remaining2 = capacity[0][2] - a_answer - y_answer - z_answer;
    assert(remaining0 >= 0 && remaining1 >= 0 && remaining2 >= 0);

    int take0 = min(remaining0, D[1]);
    int take1 = min(remaining1, D[2]);
    int take2 = min(remaining2, D[4]);

    cout << a_answer << ' ' << x_answer << ' ' << y_answer << ' ' << take0 << ' ' << z_answer << ' ' << take1 << ' ' << take2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}