#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())

const int N = 123456;
int BLOCK_SIZE;

struct Query{
	int left_bound;
	int right_bound;
	int index;
};

bool comp(Query a, Query b){
	if(a.left_bound / BLOCK_SIZE == b.left_bound / BLOCK_SIZE)
		return a.right_bound < b.right_bound;
	return (a.left_bound / BLOCK_SIZE < b.left_bound / BLOCK_SIZE);
}

map<ll,int>st;
int vl = 1;

void add_to_map(ll x){
	if(st.count(x))
		return;	
	st[x] = vl++;
}

ll cnt[N * 3 + 12345];
ll prefix[N];
ll arr[N];
int low[N];
int up[N];
int current[N];

int main(){
	fastIO;
	int n;
	ll k;
	cin >> n >> k;
	BLOCK_SIZE = (int)(sqrt(n) + 1);
	ll x;
	for(int i = 1;i<=n;i++){
		cin >> x;
		if(x == 2)
			arr[i] = -1LL;
		else
			arr[i] = 1LL;
	}
	for(int i = 1;i<=n;i++){
		cin >> x;
		arr[i] *= x;
		prefix[i] = prefix[i-1] + arr[i];
	}
	for(int i = 0;i<=n;i++){
		add_to_map(prefix[i]);
		add_to_map(prefix[i] + k);
		add_to_map(prefix[i] - k);
		low[i] = st[prefix[i] -  k];
		up[i] = st[prefix[i] + k];
		current[i] = st[prefix[i]];
	}
	int q;
	cin >> q;
	Query st[q];
	ll store[q];
	for(int i = 0;i<q;i++){
		cin >> st[i].left_bound >> st[i].right_bound;
		st[i].index = i;
		st[i].left_bound--;
	}
	sort(st,st+q,comp);
	int l = 0,r = -1;
	ll ans = 0;
	for(int j = 0;j<q;j++){
		while(l > st[j].left_bound){
			l--;
			ans += cnt[up[l]];
			cnt[current[l]]++;
		}
		while(l < st[j].left_bound){
			cnt[current[l]]--;
			ans -= cnt[up[l]];
			l++;
		}
		while(r > st[j].right_bound){
			cnt[current[r]]--;
			ans -= cnt[low[r]];
			r--;
		}
		while(r < st[j].right_bound){
			r++;
			ans += cnt[low[r]]; 
			cnt[current[r]]++;
		}
		store[st[j].index] = ans;
	}
	for(int i = 0;i<q;i++)cout << store[i] <<"\n";
	return 0;
}