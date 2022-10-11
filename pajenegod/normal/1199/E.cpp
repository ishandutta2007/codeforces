#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main () {
    cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<bool> matched(3*n,false);
		vector<int > matching;
		for (int i=0;i<m;++i) {
			int a,b;
			cin >> a >> b;
			if (!matched[a-1] && !matched[b-1] ){
				matched[a-1]=matched[b-1]=true;
				matching.push_back(i);
			}			
		}
		if (matching.size()>=n) {
			cout << "Matching\n";
			for (int i=0;i<n;++i) cout << matching[i]+1 << " ";
		} else {
			cout << "IndSet" << '\n';
			int ans=0;
			for (int i=0;ans<n;++i) if (!matched[i]) {++ans; cout << i+1 << " ";}
			
		}
		cout << '\n';
	}
	
}