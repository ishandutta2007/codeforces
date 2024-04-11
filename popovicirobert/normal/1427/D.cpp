#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;




int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> n;
   	vector<int> a(n);
   	int l, r;
   	for(i = 0; i < n; i++) {
   		cin >> a[i];
   		if(a[i] == 1) {
   			l = r = i;
   		}
   	}

   	vector<vector<int>> sol;
   	while(true) {
   		int l1 = -1, r1;
   		int l2 = -1, r2;
   		for(i = 0; i < n; i++) {
   			for(int j = i + 1; j < n; j++) {
   				if(a[i] == a[j] + 1) {
   					l1 = i;
   					r2 = j;
   				}
   			}
   		}
   		if(l1 == -1) {
   			break;
   		}
   		r1 = l1;
   		while(r1 + 1 < n && a[r1] == a[r1 + 1] - 1) {
   			r1++;
   		}
   		l2 = r2;
   		while(l2 > 0 && a[l2] == a[l2 - 1] + 1) {
   			l2--;
   		}


   		//[] [l1, r1] [] [l2, r2] []
   		//[] [l2, r2] [l1, r1] [] []

   		sol.push_back(vector<int>());
		auto add = [&](int x) {
   			if(x > 0) {
   				sol.back().push_back(x);
   			}
   		};

   		add(l1);
   		add(l2 - l1);
   		add(r2 - l2 + 1);
   		add(n - 1 - r2);

   		vector<int> new_a;
   		int pos = n;
   		for(i = (int)sol.back().size() - 1; i >= 0; i--) {
   			for(int j = pos - sol.back()[i]; j < pos; j++) {
   				new_a.push_back(a[j]);
   			}
   			pos -= sol.back()[i];
   		}
   		a = new_a;

   		/*for(auto it : a) {
   			cerr << it << " ";
   		}
   		cerr << "\n";*/
   	}

   	cout << sol.size() << "\n";
   	for(auto arr : sol) {
   		cout << arr.size() << " ";
   		for(auto it : arr) {
   			cout << it << " ";
   		}
   		cout << "\n";
   	}
	
    return 0;
}