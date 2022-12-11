#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
const int BL = 330;

struct Query{
	int left_bound;
	int right_bound;
	int index;
	bool operator< (Query X){
		if(left_bound / BL == X.left_bound / BL){
			return right_bound < X.right_bound;
		}
		return left_bound < X.left_bound;
	}
};

vector<int> pos[N];
vector<int> sp[N];
vector<int> eq[N];

deque<int> use[N];
int good[N][2];

int is_prog[N];

int a[N];
int id[N];

int cnt[N];

int prog_cnt = 0;
int dist = 0;

void change(int idx){
	prog_cnt -= is_prog[idx];
	is_prog[idx] = (good[idx][0] == 0 && cnt[idx] > 0);
	prog_cnt += is_prog[idx];
}

void add(int idx, int d){
	int el = a[idx];
	cnt[el] ++ ;
	if(cnt[el] == 1)
		dist ++ ;
	if(d == 0){
		if(use[el].size() > 1){
			good[el][eq[el][id[idx]]] ++ ;
		}
		use[el].push_front(id[idx]);
	}
	else{
		if(use[el].size() > 1){
			good[el][eq[el][id[idx] - 2]] ++ ;
		}
		use[el].push_back(id[idx]);
	}
	change(el);
}

void rem(int idx, int d){
	int el = a[idx];
	cnt[el] -- ;

	if(cnt[el] == 0)
		dist -- ;
	
	if(d == 0){
		if(use[el].size() > 2){
			good[el][eq[el][id[idx]]] -- ;
		}
		use[el].pop_front();
	}
	else{
		
		if(use[el].size() > 2){
			good[el][eq[el][id[idx] - 2]] -- ;
		}
		use[el].pop_back();
	}
	change(el);
}

int main(){
	fastIO;
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++ ){
		cin >> a[i];
		id[i] = pos[a[i]].size();
		pos[a[i]].push_back(i);
	}
	for(int i = 1; i < N ; i ++ ){
		for(int j = 1; j  < pos[i].size(); j ++ ){
			sp[i].push_back(pos[i][j] - pos[i][j - 1]);
		}
	}
	for(int i = 1; i < N; i ++ ){
		for(int j = 1; j < sp[i].size(); j ++ ){
			eq[i].push_back(sp[i][j] == sp[i][j - 1]);
		}
	}
	int q;
	cin >> q;
	Query Q[q];
	for(int i = 0; i < q; i ++ ){
		cin >> Q[i].left_bound >> Q[i].right_bound;
		Q[i].left_bound -- ;
		Q[i].right_bound -- ;
		Q[i].index = i;
	}
	
	int answ[q];
	
	sort(Q, Q + q);
	
	int cl = 0, cr = -1;
	int tl, tr;
	for(int i = 0 ;i < q; i ++ ){
		tl = Q[i].left_bound;
		tr = Q[i].right_bound;
		while(cr < tr){
			add(++ cr , 1);
		}
		while(cl < tl){
			rem(cl ++ , 0); 
		}
		while(cl > tl){
			add(-- cl , 0);
		}
		while(cr > tr){
			rem(cr -- , 1);
		}
		answ[Q[i].index] = dist + (prog_cnt == 0);
	}
	for(int i = 0; i < q; i ++ ){
		cout << answ[i] << "\n";
	}
	return 0;
}