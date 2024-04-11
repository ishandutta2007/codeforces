#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define ld long double
#define ll long long
#define mp make_pair

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	map<int, vector<pair<int, int>>> v;
	map<int, vector<int>> ans;
	vector<int> p;
	string s;
	cin >> s;
	int now = -1, lol = 0, x = 1;
    while(x){
        x = 0;
        now++;
        for (int i = 0; i < s.size() - 1; i++){
            if (s[i] == 'R' && s[i + 1] == 'L'){
                ans[now].pb(i + 1);
                swap(s[i], s[i + 1]);
                lol++;
                p.pb(i + 1);
                x = 1;
                i++;
            }
        }
    }
	if (now > k || lol < k) {
		cout << -1;
		return 0;
	}
	else {
		int cnt = 0, j = 0;
		for (int i = 0; i < k; i++) {
			if (lol - (cnt + ans[i].size()) >= k - i - 1) {
				j += ans[i].size();
				cnt += ans[i].size();
				cout << ans[i].size() << " ";
				for (auto to : ans[i]) cout << to << " ";
				cout << '\n';
			}
			else {
                cout << (lol - cnt) - (k - i - 1) << " ";
				while (lol - cnt - 1 >= k - i - 1) {
					cout << p[j] << " ";
					cnt++;
					j++;
				}
				cout << '\n';
				for (int l = i + 1; l < k; l++) {
					cout << 1 << " " << p[j] << '\n';
					j++;
				}
				break;
			}
		}
	}
	return 0;
}