#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 100 + 10;

string s[N];
int a[N];
int cur[N];
vector<int> ans;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    while (true) {
        int nom = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == cur[i]) {
                nom = i;
                break;
            }
        }
        if (nom == -1) {
            break;
        }
        ans.push_back(nom + 1);
        
        for (int i = 0; i < n; i++) {
            if (s[nom][i] == '1') {
                cur[i]++;
            }
        }
    }
    
    cout << ans.size() << "\n";
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    return 0;
}