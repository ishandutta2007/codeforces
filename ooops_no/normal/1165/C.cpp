#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i = 0;
    string s, s1 = "";
    cin >> n >> s;
    for (auto to : s){
    	if (i % 2 == 0){
    		s1 += to;
    		i++;
    	}
    	else{
    		if (to != s1[i - 1]){
    			s1 += to;
    			i++;
    		}
    	}
    }
    if (i % 2 == 0){
    	cout << n - i << endl << s1;
    }
    else{
    	cout << n - i + 1 << endl << s1.substr(0, i - 1);
    }
}