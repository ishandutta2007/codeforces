//In the name of God
#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
int a[maxn][maxn];
int n;
vector<int> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++){
		bool x = true;
		for(int j = 0; j < n; j++)
			if(a[i][j] == 3 or a[i][j] == 1)
				x = false;
		if(x)
			ans.push_back(i + 1);
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}