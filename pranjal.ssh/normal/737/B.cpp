#include <bits/stdc++.h>
using namespace std;


int main() 
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	
	int n, a, b, k;    
    cin >> n >> a >> b >> k;
    string A;cin >> A;
    vector<pair<int, int>>B;

    
    for (int i = 0; i < n; ++i) {
    	if (A[i] == '0' and (i == 0 or A[i - 1] == '1'))
    		B.push_back({1, i});
    	else if (A[i] == '0') B.back().first++;
    }
    vector<int> ans;
    int sum = 0;

    for (auto it : B) {
    	sum += it.first / b;
    }

    for (auto it = B.begin(); it != B.end(); ++it) {
    	if (it->first < b) {
    		continue;
    	}
    	ans.push_back(it->second + b - 1);
    	it->second += b;
    	it->first -= b;
    	--sum;
    	if (sum < a) break;
    	--it;
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i + 1 << " ";

	return 0;	
}