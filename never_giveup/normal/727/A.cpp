#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

vector<int> ans;

ll a, b;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> a >> b;
    ans.push_back(b);
    while (b > a){
        if (b % 10 == 1)
            b /= 10;
        else
        if (b % 2 == 0){
            b /= 2;
        }
        else{
            cout << "NO";
            return 0;
        }
        ans.push_back(b);
    }
    if (b < a){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
}