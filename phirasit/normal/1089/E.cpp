#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int i = 0, j = 0;
    ++n;
    while (n > 2) {
        ++i;
        cout << (char) (j + 'a') << i << " ";
        --n;
        if (n == 3 && i == 7) {
            cout << "g7 g8 h8" << endl;
            return 0;
        }
        for (int jj = 7 - (i == 8); jj >= 0 && n > 2; --jj) {
            if (jj != j) {
                cout << (char) (jj + 'a') << i << " ";
                --n;
            }
            if (n <= 2) { j = jj; break; }
        }
        if (n > 2)
        j = (j == 0 ? 1 : 0);
    }
    if (j < 7 && i <= 7) 
        cout << (char) (j + 'a') << 8 << " h8" << endl;
    else if (i <= 7) cout << "h7 h8" << endl;
    else cout << "a8 h8" << endl;
    return 0;
}