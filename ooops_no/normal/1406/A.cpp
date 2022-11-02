#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<deque>
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> have(101);
        for (int i = 0; i < n; i++){
            int a;
            cin >> a;
            have[a]++;
        }
        int sum = 0;
        for (int i = 0; i < 101; i++){
            if (have[i] == 0){
                sum += i;
                break;
            }
            have[i]--;
        }
        for (int i = 0; i < 101; i++){
            if (have[i] == 0){
                sum += i;
                break;
            }
            have[i]--;
        }
        cout << sum << endl;
    }
    return 0;
}