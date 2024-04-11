#include <bits/stdc++.h>
#define AIDAR ASADULLIN
#define all(x) x.begin(), x.end()
using namespace std;
const int max_n = 501;
const int max_m = 250001;
int cost[max_m];
int gr[max_n][max_n];
int timer = 0;

struct xor_one_move_5_or_one_move_5{
	int x, ind1, ind2;
	xor_one_move_5_or_one_move_5(int x, int ind1, int ind2): x(x), ind1(ind1), ind2(ind2){
	}
};


bool comp(xor_one_move_5_or_one_move_5&A, xor_one_move_5_or_one_move_5&B){
	if (A.x != B.x) return A.x < B.x;
	return make_pair(A.ind1, A.ind2) < make_pair(B.ind1, B.ind2);
}

int p[max_m]; 

void init(){
	for(int i = 0; i < max_m; i++)
		p[i]= i;
}

int find(int x){	
	if(x == p[x])return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y){
	p[find(x)] = find(y);
}

void solve(int n){
	timer = n;
	init();
	vector<xor_one_move_5_or_one_move_5> a;
	vector<pair<int,int>> edge;
	for(int i = 0; i < n; i++)cost[i] = gr[i][i];
	for(int i = 0; i < n; i++)
		for(int j =0; j < n; j++)
			a.emplace_back(gr[i][j], i, j);
	sort(all(a), comp);
	for(int i = 0; i < n * n ;i++){
		int ind1 = find(a[i].ind1);
		int ind2 = find(a[i].ind2);
		if(ind1==ind2)continue;
		if(cost[ind1] > cost[ind2])swap(ind1,ind2);
		if(cost[ind2] < a[i].x){
			edge.emplace_back(ind2, timer);
			merge(ind2, timer);
			ind2 = find(ind2);
			cost[timer++] = a[i].x;
		}
		edge.emplace_back(ind1, ind2);
		merge(ind1, ind2);
	}
	cout << timer << '\n';
	for(int i = 0; i < timer; i++)
		cout << cost[i] << " ";
	cout << '\n' << timer << '\n';
	sort(all(edge));
	for(auto x : edge){
		cout << x.first + 1 << " " << x.second + 1 << "\n";
	}
}


signed main(){
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
#ifdef _Debunk
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    	for(int j = 0; j < n ; j++)
    		cin >> gr[i][j];
   	solve(n);
}
//            