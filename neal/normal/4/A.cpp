#include <iostream>
using namespace std;

// Create a namespace to avoid naming conflicts.
namespace neal {

int W;

void solve_problem() {
    cin >> W;
    cout << (W % 2 == 0 && W > 2 ? "YES" : "NO") << '\n';
}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    neal::solve_problem();
    return 0;
}