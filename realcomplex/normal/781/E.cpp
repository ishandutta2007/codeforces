#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct Barrier{
	int row;
	int left_b;
	int right_b;
	int up;
	
	bool operator< ( Barrier T) const {
		 return row < T.row;
	 }
};

const int N = (int)1e5 + 9;
const int MOD = (int)1e9 + 7;

bool rem[N];
vector<int> Tree[N * 4];

void build(int node, int cl, int cr){
	
	if(cl == cr){
		Tree[node].push_back(0);
		return;
	}
	
	int md = (cl + cr) / 2;
	build(node * 2, cl, md);
	build(node * 2 + 1, md + 1, cr);
}

void insert(int node, int cl, int cr, int tl, int tr, int x){
	if(cr < tl)
		return;
	if(cl > tr)
		return;
	if(cl >= tl && cr <= tr){
		Tree[node].push_back(x);
		return;
	}
	int md = (cl + cr) / 2;
	insert(node * 2, cl, md, tl, tr, x);
	insert(node * 2 + 1, md + 1, cr, tl, tr, x);
	
}

int ask(int node, int cl, int cr, int index){
	while(!Tree[node].empty()){
		if(rem[Tree[node].back()]){
			break;
		}
		Tree[node].pop_back();
	}
	int ret = 0;
	if(!Tree[node].empty()){
		ret = Tree[node].back();
	}
	
	if(cl == cr)
		return ret;
	
	int md = (cl + cr) / 2;
	if(index <= md)
		ret = max(ret, ask(node * 2, cl, md, index));
	else
		ret = max(ret, ask(node * 2 + 1, md + 1, cr, index));
	return ret;
}

int answ[N];

int main(){
	fastIO;
	int h, w, n;
	cin >> h >> w >> n;
	
	Barrier cur;
	vector<Barrier> use;
	
	answ[0] = 1;
	
	build(1, 0, w - 1);
	
	for(int i = 0 ; i < n; i ++ ){
		cin >> cur.row >> cur.left_b >> cur.right_b >> cur.up;
		cur.left_b -- ;
		cur.right_b -- ;
		
		use.push_back(cur);
	}
	use.push_back({0, 0, 0, 0});
	sort(use.begin(), use.end());
	
	set<pii> nt;
	
	int check_row;
	int idx;
	
	int go_lef, go_rig;
	
	rem[0] = true;
	
	for(int i = 1 ; i < use.size(); i ++ ){
		while(!nt.empty()){
			check_row = nt.begin() -> fi;
			idx = nt.begin() -> se;
			if(use[i].row > check_row){
				rem[idx] = false;
				nt.erase(nt.begin());
			}
			else{
				break;
			}
		}
		
		
		if(use[i].left_b == 0)
			go_lef = use[i].right_b + 1;
		else
			go_lef = use[i].left_b - 1;
			
		if(use[i].right_b != w - 1)
			go_rig = use[i].right_b + 1;
		else
			go_rig = use[i].left_b - 1;
		
		
		go_lef = ask(1, 0, w - 1, go_lef);
		go_rig = ask(1, 0, w - 1, go_rig);
		
		
		answ[i] = (answ[go_lef] + answ[go_rig]) % MOD;
		
		rem[i] = true;
		nt.insert(mp(use[i].row + use[i].up, i));
		insert(1, 0, w - 1, use[i].left_b, use[i].right_b, i);
	}
	
	while(!nt.empty()){
		check_row = nt.begin() -> fi;
		idx = nt.begin() -> se;
		if(h + 1 > check_row){
			rem[idx] = false;
			nt.erase(nt.begin());
		}
		else{
			break;
		}
	}
	
	int ans = 0;
	
	for(int i = 0 ;i < w; i ++ ){
		ans = (ans + answ[ask(1, 0, w - 1, i)]) % MOD;
	}
	cout << ans << "\n";
	return 0;
}