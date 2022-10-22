#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int qry(string s) {
	cout << s << endl;
	int x; cin >> x;
	if (x==0) {
		//we are correct;
		exit(0);
	}
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n=qry("a")+1;
	if (n==301) {
		qry(string(300, 'b'));
		assert(0);
	}
	int last=qry(string(n, 'a'));
	if (last==n) {
		qry(string(n-1, 'b'));
		assert(0);
	}
	string ans(n, 'a');
	for (int i=0; i<n-1; ++i) {
		ans[i]='b';
		int temp=qry(ans);
		assert(abs(last-temp)==1);
		if (temp>last) {
			//rollback change
			ans[i]='a';
		}
		else
			last=temp;
	}
	if (last>0) {
		assert(last==1);
		ans[n-1]='b';
	}
	qry(ans);
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/