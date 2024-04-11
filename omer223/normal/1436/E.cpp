#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<class T>
struct segmentree {
private:
	vector<T> seg, original;
	int n;
	T action(const T& lhs, const T& rhs) {
		return max(lhs, rhs); //CHECK
	}
	void build(int i, int l, int r) {
		if (l > r)return;
		else if (l == r)seg[i] = original[l];
		else {
			int mid = (l + r) / 2;
			build(2 * i, l, mid);
			build(2 * i + 1, mid + 1, r);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
	T queryUtil(int i, int cl, int cr, int l, int r) {
		if (l > r)return -1e9; //CHECK
		else if (l == cl && r == cr)return seg[i];
		else {
			int mid = (cl + cr) / 2;
			T a = queryUtil(2 * i, cl, mid, l, min(mid, r)),
				b = queryUtil(2 * i + 1, mid + 1, cr, max(mid + 1, l), r);
			return action(a, b);
		}
	}
	void updateUtil(int i, int l, int r, int pos, T val) {
		if (l == r)seg[i] = val;
		else {
			int mid = (l + r) / 2;
			if (pos <= mid)updateUtil(2 * i, l, mid, pos, val);
			else updateUtil(2 * i + 1, mid + 1, r, pos, val);
			seg[i] = action(seg[2 * i], seg[2 * i + 1]);
		}
	}
public:
	segmentree(int size) {
		n = size;
		seg.resize(4 * n);
		fill(seg.begin(), seg.end(), 0);
	}
	segmentree(vector<T> orig) {
		original = orig;
		n = orig.size();
		seg.resize(4 * n);
		build(1, 0, n - 1);
	}
	T query(int l, int r) {
		return queryUtil(1, 0, n - 1, max(0,l), min(r,n-1));
	}
	void update(int i, T val) {
		updateUtil(1, 0, n - 1, i, val);
	}
};

const int sz = 1e5 + 5;
int n=0;
int a[sz], nxt[sz];
vector<int> closest;
vector<int> adj[sz];
bitset<sz> vis;



void input() {
    cin>>n;
    closest.resize(n + 1, n + 1);
	for (int i = 0; i < n; i++) {
	    cin>>a[i];
	    adj[a[i]].pb(i);
	}
	for (int x = 1; x <= n; x++){
	    adj[x].pb(n + 1);
	    closest[x] = adj[x][0];
	    for (int i =0;i<adj[x].size()-1;i++){
	        nxt[adj[x][i]]=adj[x][i+1];
	    }
	}
}

bitset<sz> found;

int main() {
	fast;
	input();
	segmentree<int> seg(closest);
	if(adj[1].size()==n+1){
	    cout<<1<<'\n';
	    return 0;
	}
	found[1]=1;
	for (int i = 0; i < n; i++) {
	    if(i==0){
	        for (int v = 2; v <= n; v++) {
	            if(seg.query(1, v-1)<closest[v])found[v]=1;
	        }
	    }
	    else{
	        int target=a[i-1];
	        if(target!=a[i] &&target!=1&&seg.query(1,target-1)<nxt[i-1])found[target]=1;
	    }
	    seg.update(a[i], nxt[i]);
	}
	bool bad=0;
	for (int i=1;i<=n;i++){
	    if(adj[i].size()==1)bad=1;
	}
	found[n+1]=!bad;
	for (int i =1;i<=n+1;i++){
	    if(!found[i]){
	        cout<<i<<'\n';
	        return 0;
	    }
	}
	cout<<n+2<<'\n';
	return 0;
}