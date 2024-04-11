#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long
#define ld long double
#define ll long long
#define mp make_pair

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
        string s;
        cin >> s;
        vector<bool> used(n);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '-'){
                used[i] = 1;
                used[(i + 1) % n] = 1;
            }
        }
        bool x = 0, x1 = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '-') continue;
            if (s[i] == '<') x = 1;
            else x1 = 1;
        }
        if (!x || !x1){
            cout << n << endl;
        }
        else{
            int cnt = 0;
            for (int i = 0; i < n; i++){
                if (used[i]){
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
	}
	return 0;
}