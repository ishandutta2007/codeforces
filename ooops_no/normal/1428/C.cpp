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
        string s;
        cin >> s;
        int n = s.size(), ans = s.size();
        deque<pair<char, int>> q;
        for (int i = 0; i < n; i++){
            if (s[i] == 'B'){
                if (q.size() > 0){
                    q.back().second--;
                    ans -= 2;
                }
                else{
                    q.pb({'B', 1});
                }
            }
            else{
                if (q.size() > 0 && q.back().first == 'A'){
                    q.back().second++;
                }
                else{
                    q.pb({'A', 1});
                }
            }
            if (q.back().second == 0){
                q.pop_back();
            }
        }
        cout << ans << endl;
	}
	return 0;
}