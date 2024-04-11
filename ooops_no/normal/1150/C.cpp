#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<bool> used(1e6);
    int cnt = 0, k = 0;
    for (int i = 0; i < n; i++){
    	int a;
    	cin >> a;
    	if (a == 1){
    		cnt++;
    	}
    	else{
    		k++;
    	}
    }
    used[1] = 1;
    for (int i = 2; i <= 5e5; i++){
    	if (!used[i]){
    		for (int j = i * 2; j <= 1e6; j += i){
    			used[j] = 1;
    		}
    	}
    }
    int cc = 0;
    while(cnt > 0 || k > 0){
    	if (k == 0){
    		while(cnt > 0){
    			cnt--;
    			cout << 1 << " ";
    		}
    		continue;
    	}
    	if (cnt == 0){
    		while(k > 0){
    			k--;
    			cout << 2 << " ";
    		}
    		continue;
    	}
    	if (!used[cc + 1] && cnt > 0){
    		cout << 1 << " ";
    		cnt--;
    		cc += 1;
    	}
    	else if (k > 0){
    		cout << 2 << " ";
    		k--;
    		cc += 2;
    	}
    }
}