#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
#define p1 1000000007
 
using namespace std;
typedef long long ll;

struct node{
	int val;
	node* left = nullptr;
	node* right = nullptr;
	node(int _val, int l, int r);
	node(void) : val(-1), left(nullptr), right(nullptr){};
	void operator=(node* A);
};

node N[100001];
set<int> OK;
vector<int> elem;
node::node(int _val, int l, int r){
	val = _val;
	left = (l == -1 ? nullptr : &N[l]);
	right = (r == -1 ? nullptr : &N[r]);
}
 
void dfs(node* A, int L, int R){
	if(A == nullptr){
		return;
	}
	if(L <= A->val && A->val <= R){
		OK.insert(A->val);
	}
	dfs(A->left, L, min(R, A->val-1));
	dfs(A->right, max(L, A->val+1), R);
}

void node::operator=(node* A){
	val = A->val;
	left = A->left;
	right = A->right;
}

bool is_root[100001];
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		is_root[i] = true;
	}
	for(int i=1;i<=n;i++){
		int v, l, r;
		cin >> v >> l >> r;
		N[i] = node(v, l, r);
		elem.push_back(v);
		if(l != -1){
		    is_root[l] = false;
		}
		if(r != -1){
		    is_root[r] = false;
		}
	}
	int root = -1;
	for(int i=1;i<=n;i++){
		if(is_root[i]){
			root = i;
			break;
		}
	}
	node* _root = &N[root];
	dfs(_root, 0, 1000000000);
	int ans = 0;
	for(int i=0;i<n;i++){
		ans += OK.find(elem[i]) == OK.end();
	}
	cout << ans;
	return 0;
}