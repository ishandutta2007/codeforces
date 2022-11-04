#include<iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<tuple>
#include<queue>
using namespace std;
const long long INF = 1000000000000000000;
const int Y = 200000;
const long long m = 1000000007;
long long arr[200000][26];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    arr[0][s[0] - 'a']++;
    int len = s.length();
    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < 26; ++j)arr[i][j] = arr[i - 1][j];
        ++arr[i][s[i] - 'a'];
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        bool ans = true;
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (a == b) {
            cout << "Yes\n";
            continue;
        }
        vector<int>sup;
        if(a!=0)for (int j = 0; j < 26; ++j) {
            if (arr[a-1][j] != arr[b][j]) {
               // cout << (char)(j + 'a') << endl;
                sup.push_back(arr[b][j] - arr[a-1][j]);
            }
        }
        else {
            for (int j = 0; j < 26; ++j) {
                if (0!= arr[b][j]) {
                    // cout << (char)(j + 'a') << endl;
                    sup.push_back(arr[b][j] - 0);
                }
            }
        }
        //cout << sup.size() << endl;
        if (sup.size() > 2) {
            cout << "Yes\n";
        }
        else {
            if (sup.size() == 1) {
                cout << "No\n";
            }
            else {
                if (s[a] == s[b])cout << "No\n";
                else cout << "Yes\n";
            }
        }
    }
    return 0;
}