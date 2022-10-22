#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class A> ostream& operator<< (ostream& out, const vector<A> &v) {
	out << "[";
	for (int i=0; i<v.size(); ++i) {
		out << v[i];
		if (i+1<v.size()) out << ", ";
	}
	return out << "]";
}

const ll INF=(ll)(1e18)+99;
int largest(ll x) {return 63-__builtin_clzll(x);}
bool OVERFLOW(ll a, ll b) {return largest(a)+largest(b)>=60;}

ll add(ll a, ll b) {return min(INF, a+b);}
ll mul(ll a, ll b) {if (OVERFLOW(a, b)) return INF; return min(a*b, INF);}

ll fact[51], cnt[51], dp[51];
vector<int> get(int n, ll k, int offset=0) {
	if (n==1) {assert(k==1); return {1+offset};}
	if (n==2) {assert(k==1); return {2+offset, 1+offset};}
	assert(k<=fact[n-2]);
	vector<int> left(n-1);
	//vector<int> cor(n, -1);
	iota(left.begin(), left.end(), 1);
	vector<int> ret={n};
	for (int i=2; i<n; ++i) {
		for (int j=0; j<left.size(); ++j) {
			int x=left[j];
			//if (x==i||x==cor[i])
			//	continue;
			if (x==i) continue;
			if (x<i) {
				int cur=x;
				vector<bool> vis(n, 0);
				while(1) {
					vis[cur]=1;
					cur=ret[cur-1];
					if (cur>=i||vis[cur])
						break;
				}
				//cerr << cur << "\n";
				if (cur==i) continue;
			}
			if (k<=fact[n-i-1]) {
				//cor[x]=i;
				ret.push_back(x);
				left.erase(left.begin()+j);
				break;
			}
			k-=fact[n-i-1];
		}
		//cout << k << ' ' << ret << "\n";
	}
	assert(left.size()==1&&k==1);
	ret.push_back(left[0]);
	for (int &i: ret)
		i+=offset;
	return ret;
}


int n;
ll k;

void test_case() {
	cin >> n >> k;
	if (k>dp[n]) {
		cout << "-1\n";
		return;
	}
	vector<int> ans;
	for (int st=0; st<n;) {
		int found=-1;
		for (int i=st+1; i<n; ++i) {
			if (k>mul(cnt[i-st], dp[n-i]))
				k-=mul(cnt[i-st], dp[n-i]);
			else {
				found=i;
				ll x=dp[n-i];
				ll y=(k+x-1)/x;
				vector<int> c=get(i-st, y, st);
				for (int i: c)
					ans.push_back(i);
				k-=(y-1)*x;
				break;
			}
		}
		//cout << found << ' ' << k << "\n";
		if (found!=-1) {
			st=found;
		}
		else {
			vector<int> c=get(n-st, k, st);
			for (int i: c)
				ans.push_back(i);
			break;
		}
	}
	for (int i: ans)
		cout << i << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fact[0]=cnt[0]=cnt[1]=dp[1]=1;
	for (int i=1; i<=50; ++i)
		fact[i]=mul(fact[i-1], i);
	for (int i=2; i<=50; ++i) {
		cnt[i]=fact[i-2];
		dp[i]=cnt[i];
		for (int j=1; j<i; ++j)
			dp[i]=add(dp[i], mul(cnt[j], dp[i-j]));
	}

	//for (int i=1; i<=50; ++i)
	//	cout << dp[i] << "\n";
	int t=1;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}