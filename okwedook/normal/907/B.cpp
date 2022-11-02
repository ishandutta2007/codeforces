#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<string> arr(11);

int conv(int a) {
    if (a == 0) return 0;
    if (a == 1) return 4;
    if (a == 2) return 8;
}

void change(int x1, int y1, int x2, int y2, char c) {
    arr[conv(x1) + x2][conv(y1) + y2] = c;
}

bool dot(int x1, int y1, int x2, int y2) {
    return arr[conv(x1) + x2][conv(y1) + y2] == '.';
}


int main() { 
    char c;
    int ptr = 0;
    for (auto &i : arr) getline(cin, i);
    int x, y;
    cin >> x >> y;
    x = ((x - 1) % 3), y = ((y - 1) % 3);
    int count = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            count += dot(x, y, i, j);
    if (count > 0) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (dot(x, y, i, j))
                    change(x, y, i, j, '!');
    } else {
        for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
                for (int i = 0; i < 3; ++i)
                    for (int j = 0; j < 3; ++j)
                        if (dot(x, y, i, j))
                            change(x, y, i, j, '!');
    }
    for (int i = 0; i < 11; ++i) cout << arr[i] << endl;
    //system("pause");     
    return 0; 
}