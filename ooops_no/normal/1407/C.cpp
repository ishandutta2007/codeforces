#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<deque>

using namespace std;

#define pb push_back
#define int long long
#define ld long double

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 1){
        cout << "! " << 1 << endl;
        return 0;
    }
    if (n == 2){
        int p;
        cout << "? " << 1 << " " << 2 << endl;
        cin >> p;
        if (p == 0){
            cout << "! " << 2 << " " << 1 << endl;
        }
        else{
            cout << "! " << 1 << " " << 2 << endl;
        }
        return 0;
    }
    int i = 0;
    vector<int> ans(n);
    for (int j = 1; j < n; j++){
        int p, k;
        cout << "? " << i + 1 << " " << j + 1 << endl;
        cin >> p;
        cout << "? " << j + 1 << " " << i + 1 << endl;
        cin >> k;
        if (p > k){
            ans[i] = p;
            i = j;
        }
        else{
            ans[j] = k;
        }
    }
    ans[i] = n;
    cout << "! ";
    for (auto to : ans){
        cout << to << " ";
    }
    cout << endl;
    return 0;
}