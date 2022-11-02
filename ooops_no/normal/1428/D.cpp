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
	int n;
	cin >> n;
	vector<int> v(n);
	set<int> st;
	for (int i = 0; i < n; i++){
        cin >> v[i];
        if (v[i] == 1) st.insert(i);
	}
	int row = n;
	vector<int> u;
	vector<pair<int,int>> ans;
	for (int i = 0; i < n; i++){
        if (v[i] == 3){
            u.pb(i);
        }
        else if (v[i] == 2){
            if (st.size() == 0){
                cout << -1;
                return 0;
            }
            int val = *st.begin();
            if (u.size() == 0){
                ans.pb({row, i + 1});
                ans.pb({row, val + 1});
                row--;
            }
            else{
                row -= u.size();
                u.pb(i);
                for (int j = 0; j < u.size() - 1; j++){
                    ans.pb({row, u[j] + 1});
                    ans.pb({row, u[j + 1] + 1});
                    row++;
                }
                ans.pb({row, i + 1});
                ans.pb({row, val + 1});
                row -= u.size();
            }
            st.erase(val);
            u.clear();
        }
        else{
            if (v[i] == 1){
                if (st.find(i) != st.end()){
                    if (u.size() == 0){
                        ans.pb({row, i + 1});
                        row--;
                    }
                    else{
                        row -= u.size();
                        u.pb(i);
                        for (int j = 0; j < u.size() - 1; j++){
                            ans.pb({row, u[j] + 1});
                            ans.pb({row, u[j + 1] + 1});
                            row++;
                        }
                        ans.pb({row, i + 1});
                        row -= u.size();
                    }
                    u.clear();
                }
                st.erase(i);
            }
        }
	}
	if (u.size() != 0){
        cout << -1;
        return 0;
	}
	cout << ans.size() << endl;
	for (auto to : ans){
        cout << to.first << " " << to.second << endl;
	}
	return 0;
}