#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a, b, c; //smallest factor >1 of i
vector<int> fct[20001];

int nextMult(int x, int y) {
	int choice1=y/x*x;
	int choice2=choice1+x;
	if (y-choice1<choice2-y)
		return choice1;
	return choice2;
}

int getClosest(int x, int k) { // we want x|k
	if (x==1)
		return 1;
	int closest=1e9;
	auto it = lower_bound(fct[k].begin(), fct[k].end(), x);

	if (it!=fct[k].end())
		closest=*it; --it;
	if (x-*it<closest-x)
		closest=*it;
	return closest;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i=1; i<=20000; ++i) {
		for (int j=1; j*j<=i; ++j) {
			if (i%j)
				continue;
			fct[i].push_back(j);
			if (j*j<i)
				fct[i].push_back(i/j);
			sort(fct[i].begin(), fct[i].end());
		}
	}

	int t;
	cin >> t;
	while(t--) {
		cin >> a >> b >> c;
		ar<int, 3> num;
		int ans=1e9;
		for (int i=1; i<=20000; ++i) {
			int curB=i, curA=getClosest(a, i), curC=nextMult(i, c);
			int curr=abs(a-curA)+abs(b-curB)+abs(c-curC);
			if (curr<ans) {
				ans=curr;
				num={curA, curB, curC};
			}
		}
		cout << ans << '\n';
		cout << num[0] << ' ' << num[1] << ' ' << num[2] << '\n';
	}
	return 0;
}