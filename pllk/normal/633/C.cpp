#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;

int A = 17;
int B = 987123777;

int n;
string s;
int m;
int r;

unordered_map<int,string> z;

int d[101010];
int e[101010];
int f[101010];

vector<string> v;

int main() {
    cin >> n;
    cin >> s;
    cin >> m;
    srand(time(NULL));
    B -= (rand()%10000);
    for (int i = 0; i < m; i++) {
        string u;
        cin >> u;
        ll h = 0;
        for (int i = 0; i < u.size(); i++) {
            char w = u[i];
            if (w <= 'Z') w += ('z'-'Z');
            h = (h*A+w)%B;
        }
        z[h] = u;
        r = max(r,(int)u.size());
    }
    for (int i = 0; i < n; i++) {
        ll h = 0;
        int k = i;
        for (int j = 0; j < r; j++) {
            if (k == -1) break;
            h = (h*A+s[k])%B;
            if (z.count(h) && (k == 0 || d[k-1])) {
                d[i] = 1;
                e[i] = h;
                f[i] = k-1;
            }
            k--;
        }
    }
    int k = n-1;
    while (k >= 0) {
        v.push_back(z[e[k]]);
        k = f[k];
    }
    for (int i = v.size()-1; i >= 0; i--) {
        cout << v[i] << " ";
    }
    cout << "\n";
}