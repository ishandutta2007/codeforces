#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 19;
const int AL = 26;

int str_trie[N * 17][AL];
int pri[N * 17];
int cntstr = 1;

int str_do(int t){
	++ cntstr;
	for(int i = 0 ; i < AL; i ++ )
		str_trie[cntstr][i] = str_trie[t][i];
	pri[cntstr] = pri[t];
	return cntstr;
}

int str_fin(int nod, string t){
	for(char x : t){
		nod = str_trie[nod][x - 'a'];
	}
	return pri[nod];
}

void update_str(int &nod, string t, int p){
	nod = str_do(nod);
	int cur = nod;
	for(char x : t){
		str_trie[cur][x - 'a'] = str_do(str_trie[cur][x - 'a']);
		cur = str_trie[cur][x - 'a'];
	}
	pri[cur] = p;
}

int root_str[N];
int root_bit[N];

const int BIT = 31;
int bit_trie[N * 63][2];
int subt_sum[N * 63];	
int cntbit = 1;

int bit_do(int t){
	++ cntbit;
	for(int i = 0 ; i < 2; i ++ )
		bit_trie[cntbit][i] = bit_trie[t][i];
	subt_sum[cntbit] = subt_sum[t];
	return cntbit;
}

int bit_fin(int nod, int mask){
	int answ = 0;
	for(int bit = BIT - 1; bit >= 0 ; bit -- ){
		if(mask & (1 << bit)){
			answ += subt_sum[bit_trie[nod][0]];
			nod = bit_trie[nod][1];
		}
		else{
			nod = bit_trie[nod][0];
		}
		
	}
	return answ;
}

void bit_upd(int &nod, int mask, int t){
	nod = bit_do(nod);
	int cur = nod;
	for(int bit = 30 ;  bit >= 0; bit -- ){
		if(mask & (1 << bit)){
			bit_trie[cur][1] = bit_do(bit_trie[cur][1]);
			cur = bit_trie[cur][1];
		}
		else{
			bit_trie[cur][0] = bit_do(bit_trie[cur][0]);
			cur = bit_trie[cur][0];
		}
		subt_sum[cur] += t ;
	}
}

int main(){
	int q;
	cin >> q;
	string t, s;
	int y;
	root_str[0] = 1;
	int d;
	for(int i = 1 ; i <= q; i ++ ){
		cin >> t;
		root_str[i] = root_str[i - 1];
		root_bit[i] = root_bit[i - 1];
		if(t == "set"){
			cin >> s >> y;
			d = str_fin(root_str[i], s);
			if(d != 0){
				bit_upd(root_bit[i], d,  -1);
			}
			bit_upd(root_bit[i], y, 1);
			update_str(root_str[i], s, y);
		}
		else if(t == "remove"){
			cin >> s;
			d = str_fin(root_str[i], s);
			if(d != 0){
				bit_upd(root_bit[i], d, -1);
				update_str(root_str[i], s, 0);
			}
		}
		else if(t == "undo"){
			cin >> d;
			root_str[i] = root_str[i - d - 1];
			root_bit[i] = root_bit[i - d - 1];
		}
		else if(t ==  "query"){
			cin >> s;
			d = str_fin(root_str[i], s);
			if(d == 0){
				cout << -1 << "\n";
				continue;
			}
			cout << bit_fin(root_bit[i], d) << "\n";
			fflush(stdout);
		}
	}
	return 0;
}