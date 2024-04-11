#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int _, K;
    cin >> _ >> K;
    vector<int> outputs;

    for (int skip = 0; skip <= K; skip++) {
        cout << '?';

        for (int k = 0; k <= K; k++)
            if (k != skip)
                cout << ' ' << k + 1;

        cout << endl;
        int output;
        cin >> _ >> output;
        outputs.push_back(output);
    }

    sort(outputs.begin(), outputs.end());
    int bigger = 0;

    for (int k = 0; k <= K; k++)
        if (outputs[k] == outputs.back())
            bigger++;

    cout << "! " << bigger << endl;
}