// not my code https://codeforces.com/contest/1491/submission/108720822

#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
#define Endl '\n'
#define sacnf scanf
#define fi first
#define ii pair<int,int>
#define iil pair<ll,ll>
#define se second
#define ld long double
#define mod 0
#define popcount __builtin_popcountll
#define x0 zxcxzcsacasd
#define x1 ghfghujfgfg
#define y0 olkjhdnncvcv
#define y1 bhvgrewm345345435
#define debug(x) std::cerr<<#x<<": "<<(x)<<'\n'
#define all(x) x.begin(), x.end()
using namespace std;
int n, rem;
int ask(vector<int>a, vector<int>b){
	assert(rem);
	rem--;
	cout << "? " << a.size() << " " << b.size() << '\n';
	for(auto x : a){
		cout << x << " ";
	}
	for(auto x : b){
		cout << x << " ";
	}
	cout << '\n';
	int ret;
	cin >> ret;
	return ret;
}
vector<int> collectZeros(int st, int skip, vector<int>amid){
	// all zeros are -
	for(int i = st;i <= n;i++){
		vector<int>a, b;
		a.pb(i);
		for(int j = 1; j <= n;j++){
			if(j == i || j == skip)continue;
			b.pb(j);
		}
		int x = ask(a, b);
		if(x == 0)amid.pb(i);
	}
	return amid;
}
vector<int>get(int idx){
	// ask for every one in range[idx + 1, n].
	// every zero is part of the answer.
	cerr << "in go " << idx << endl;
	vector<int>ret;
	if(idx == n || idx == n - 1){
		// defiently not -
		return ret;
	}
	int cnt = 0;
	for(int i = idx + 1; i < n;i++){
		vector<int>a, b;
		a.pb(i);
		for(int j = idx;j <= n;j++){
			if(j != i)b.pb(j);
		}
		int x = ask(a, b);
		if(x == 0)ret.pb(i);
		else cnt++;
	}
	if(cnt % 2)ret.pb(n);
	return ret;
}
void pr(vector<int>amid){
	cout << "! " << amid.size() << " ";
	for(auto x : amid){
		cout << x << " ";
	}
	cout << '\n';
}
 
int binarySearch(int r){
	cerr << "In bs " << r << endl;
	int st = 1, en = r - 1;
	vector<int>a, b;
	a.pb(r);
	while(st <= en){
		int mid = (st + en) / 2;
		// ask range[1, mid]
		// if 0 all this range is -
		// otherwise it contains S or N.
		b.clear();
		for(int i = 1;i <= mid;i++)b.pb(i);
		int x = ask(a, b);
		if(x == 0)st = mid + 1;
		else en = mid - 1;		
	}
	return st;
}

 
void test_case(){
	cin >> n;
	rem = n + log2(n);
	vector<int>amid;
	for(int i = 1;i <= n;i++){
		vector<int>a, b;
		a.pb(i);
		for(int j = i + 1;j <= n;j++){
			b.pb(j);
		}
		int x = ask(a, b);
		if(x == 0){
			amid.pb(i);
			continue;
		}
		if(x == -2){
			amid = collectZeros(i + 1, i, amid);
			pr(amid);
			return;
		}
		if(x >= 1 || x <= -3){
			amid = collectZeros(i + 1, -1, amid);
			pr(amid);
			return;
		}
		if(x == -1){
			vector<int>tmp = get(i);
			int skip = binarySearch(i);
			for(auto x : amid){
				if(x != skip)tmp.pb(x);
			}
			amid = tmp;
			pr(amid);
			return;
		}
	}
}
int main(){
    cin.sync_with_stdio(0);
	int t = 1;
	cin >> t;
	while(t--)test_case();
}