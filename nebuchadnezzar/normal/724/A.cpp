#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);


string d1, d2;

vector<string> days = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    cin >> d1 >> d2;

    int n1 = find(bend(days), d1) - days.begin();
    
    int n2 = find(bend(days), d2) - days.begin();

    if ((n1 + 28) % 7 == n2 || (n1 + 31) % 7 == n2 || (n1 + 30) % 7 == n2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}