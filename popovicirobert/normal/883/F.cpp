#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;

string str;
char stk[100];

vector <string> arr;
int id[400];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> str;
        int sz = 0;
        for(auto it : str) {
            char ch = it;
            while(sz > 0 && stk[sz] == 'k' && ch == 'h') {
                sz--;
            }
            stk[++sz] = ch;
        }
        str.clear();
        for(int j = 1; j <= sz; j++) {
            if(stk[j] == 'u')
                str += "oo";
            else
                str.push_back(stk[j]);
        }
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    cout << unique(arr.begin(), arr.end()) - arr.begin();
    //cin.close();
    //cout.close();
    return 0;
}