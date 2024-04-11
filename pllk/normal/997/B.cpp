#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

ll n;
set<int> s;
int h;

void lol(int u, int c, int z) {
    if (c == n) {
        s.insert(u);
        return;
    }
    if (1 >= z) lol(u+1,c+1,1);
    if (5 >= z) lol(u+5,c+1,5);
    if (10 >= z) lol(u+10,c+1,10);
    if (50 >= z) lol(u+50,c+1,50);
}

int main() {
    cin >> n;
    if (n <= 15) {
        lol(0,0,0);
        cout << s.size() << "\n";
    } else {
        cout << 488+(n-15)*49 << "\n";
    }
}