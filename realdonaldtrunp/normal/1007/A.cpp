#include<bits/stdc++.h>
using namespace std;

int n;

multiset<int> mt;
vector<int> v;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		mt.insert(a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size(); i++){
		auto el = mt.lower_bound(v[i]);
		if (el != mt.begin()){
			el--;
			mt.erase(el);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}