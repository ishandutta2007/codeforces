#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Node{
	ll val;
	int idx;
};

const int N = (int)1e5 + 9;
const int LG = 20;


ll d;
int n;

Node Tree[N * 2];

void init(){
	for(int i = 0; i < N * 2; i ++ ){
		Tree[i].val = -1;
		Tree[i].idx = -1;
	}
}

void upd(int id, int vl, int dx){
	id += n;
	Tree[id].val = vl;
	Tree[id].idx = dx;
	id /= 2;
	while(id > 0){
		if(Tree[id * 2].val > Tree[id * 2 + 1].val){
			Tree[id].val = Tree[id * 2].val;
			Tree[id].idx = Tree[id * 2].idx;
		}
		else{
			Tree[id].val = Tree[id * 2 + 1].val;
			Tree[id].idx = Tree[id * 2 + 1].idx;
		}
		id /= 2;
	}
}

int ask(int l, int r){
	ll mx = -1;
	int id = -1;
	l += n;
	r += n;
	while(l <= r){
		if(l % 2 == 1){
			if(Tree[l].val > mx){
				mx = Tree[l].val;
				id = Tree[l].idx;
			}
			++ l;
		}
		if(r % 2 == 0){
			if(Tree[r].val > mx){
				mx = Tree[r].val;
				id = Tree[r].idx;
			}
			-- r;
		}
		l /= 2;
		r /= 2;
	}
	return id;
}

int p[N];
int pix[N];
ll x[N];

bool comp(int a, int b ){
	return x[a] < x[b];
}

int dp[N];
int pv[N];

int main(){
	fastIO;
	init();
	cin >> n >> d;
	for(int i = 0 ; i < n; i ++ )
		cin >> x[i];
	for(int i = 0 ; i < n; i ++ )
		p[i] = i;
	sort(p, p + n, comp);
	for(int j = 0 ; j < n ; j ++ )
		pix[p[j]] = j;
	for(int j = 0 ; j < n; j ++ )
		dp[j] = -1;
	int lf, rf;
	int bix;
	int al, ar;
	for(int fin = 0 ; fin < n;  fin ++ ){
		if(x[fin] - x[p[0]] >= d){
			lf = 0;
			for(int j = LG; j >= 0 ; j -- ){
				if(lf + (1 << j) >= n)
					continue;
				if(x[fin] - x[p[lf + (1 << j)]] >= d){
					lf += (1 << j);
				}
			}
		}
		else{
			lf = -1;
		}
		
		if(x[p[n - 1]] - x[fin] >= d){
			rf = n - 1;
			for(int j = LG; j >= 0 ; j -- ){
				if(rf - (1 << j) < 0)
					continue;
				if(x[p[rf - (1 << j)]]  - x[fin] >= d){
					rf -= (1 << j);
				}
			}
		}
		else{
			rf = n;
		}
		bix = -1;
		al = ask(0, lf);
		ar = ask(rf, n - 1);
		if(al == -1){
			bix = ar;
		}
		else if(ar == -1){
			bix = al;
		}
		else{
			if(dp[p[al]] > dp[p[ar]]){
				bix = al;
			}
			else{
				bix = ar;
			}
		}

		if(bix == -1 || dp[p[bix]] == -1){
			dp[fin] = 1;
			pv[fin] = fin;
		}
		else{
			dp[fin] = dp[p[bix]] + 1;
			pv[fin] = p[bix];
		}
		upd(pix[fin], dp[fin], pix[fin]);
		
	}
	int aix = -1;
	for(int i = 0 ; i < n; i ++ ){
		if(aix == -1 || dp[i] > dp[aix]){
			aix = i;
		}
	}
	vector<int> ans;
	ans.push_back(aix);
	while(pv[aix] != aix){
		aix = pv[aix];
		ans.push_back(aix);
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(auto x : ans)
		cout << x + 1 << " ";
	return 0;
}