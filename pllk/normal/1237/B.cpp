#include <iostream>
#include <set>

using namespace std;

int n;
int a[101010];
int b[101010];
int w[101010];
set<int> s;
int c;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        w[a[i]] = i;
        s.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        if (w[b[i]] > *s.begin()) c++;
        s.erase(w[b[i]]);
    }
    cout << c << "\n";
}