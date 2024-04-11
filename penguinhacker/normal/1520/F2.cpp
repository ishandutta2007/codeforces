#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=2e5;
int n, t;
Tree<ar<int, 2>> s; // {number, prefix sum}
Tree<int> rem;

int qry(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int x;
	cin >> x;
	if (x==-1)
		exit(0);
	return (j-i+1)-x;
}

int qry2(int i) {
	auto it=s.lower_bound({i});
	if (it!=s.end()&&(*it)[0]==i)
		return (*it)[1]-rem.order_of_key(i+1);
	int x=qry(1, i);
	s.insert({i, x+(int)rem.order_of_key(i+1)});
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> t;
	for (int i=0; i<t; ++i) {
		int k;
		cin >> k;
		int lb=1, rb=n;
		while(lb<rb) {
			int mid=(lb+rb)/2;
			if (qry2(mid)>=k)
				rb=mid;
			else
				lb=mid+1;
		}
		rem.insert(lb);
		cout << "! " << lb << endl;
	}
	return 0;
}