#include <bits/stdc++.h>

using namespace std;

void run();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

const int N = 205;

int n;
int a[N];
vector<int> pos[N];

void run() {
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        int pos = 2 * i + 1;
        while (a[pos] != a[2 * i]) {
            pos++;
        }
        
        while (pos != 2 * i + 1) {
            answer++;
            swap(a[pos], a[pos - 1]);
            pos--;
        }
    }
    
    cout << answer << "\n";
}