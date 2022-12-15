#include <bits/stdc++.h>
#define SZ(v) ((int)(v).size())
using namespace std;
typedef long long ll; 

ll calcAns(const vector<int> &a, const vector<int> &b, const vector<int> &c)
{
	ll ret(0);
	ll sumA(0);
	for (auto v : a) sumA += v;
	ll sumB(0);
	for (auto v : b) sumB += v;
	ll sumC(0);
	for (auto v : c) sumC += v;
	ret = max(ret, sumA + sumB - sumC);
	if (SZ(b) > 1)
		ret = max(ret, sumA + sumB - 2 * b[0] + sumC - 2 * c[0]);
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	vector<int> v1(n1), v2(n2), v3(n3);
	for (auto &v : v1) cin >> v;
	for (auto &v : v2) cin >> v;
	for (auto &v : v3) cin >> v;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	sort(v3.begin(), v3.end());
	ll ret = max({calcAns(v1, v2, v3), calcAns(v1, v3, v2), 
							  calcAns(v2, v1, v3), calcAns(v2, v3, v1),
								calcAns(v3, v1, v2), calcAns(v3, v2, v1)});
	cout << ret << endl;
}