#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, m, k, t, a, b, c;
set<long long> s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> k;
		for (int i=0; i<n; i++){
			cin >> a;
			s.insert(a);
		}
		if (s.size() > k) cout << "-1\n";
		else{
			set<long long>::iterator it;
			it = s.begin();
			long long thing = *it;
			long long cnt = 0;
			cout << n * k << "\n";
			for (int i=0; i<n; i++){
				cnt = 0;
				it = s.begin();
				while (it!=s.end()){
					cout << (*it) << " ";
					it++;
					cnt++;
				}
				while(cnt < k){
					cout << thing << " ";
					cnt++;
				}
			}
			cout << "\n";
		}
		s.clear();
	}
}