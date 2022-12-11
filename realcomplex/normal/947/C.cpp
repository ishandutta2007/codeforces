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

const int BIT = 30;
int pak[BIT];

struct node{
	int zero_bit;
	int one_bit;
	int cnt;
};

int las_node = 1;

vector<node> trie;

void add(){
	node rt;
	rt.zero_bit = -1;
	rt.one_bit = -1;
	rt.cnt = 0;
	trie.push_back(rt);
}

int main(){
	fastIO;
	add();
	pak[0] = 1;
	for(int i = 1;i<BIT;i++)
		pak[i] = pak[i-1] * 2;
	int n;
	cin >> n;
	int A[n];
	for(int i = 0;i<n;i++)cin >> A[i];
	int key;
	int las;
	for(int i = 0;i<n;i++){
		cin >> key;
		las = 0;
		trie[las].cnt++;
		for(int j = BIT-1;j>=0;j--){
			if(key & pak[j]){
				if(trie[las].one_bit == -1){
					add();
					trie[las].one_bit = las_node;
					las_node++;
				}
				las = trie[las].one_bit;
				trie[las].cnt++;
			}
			else{
				if(trie[las].zero_bit == -1){
					add();
					trie[las].zero_bit = las_node++;
				}
				las = trie[las].zero_bit;
				trie[las].cnt++;
			}
		}
	}
	bool is;
	int ans = 0;
	for(int i  = 0;i<n;i++){
		ans = 0;
		las = 0;
		trie[las].cnt--;
		for(int j = BIT-1;j>=0;j--){
			is = true;
			if(A[i] & pak[j]){
				if(trie[las].one_bit == -1)is = false;
				else if(trie[trie[las].one_bit].cnt == 0)is = false;
			}
			else{
				if(trie[las].zero_bit == -1)is = false;
				else if(trie[trie[las].zero_bit].cnt == 0)is = false;
			}
			if(is){
				if(A[i] & pak[j]){
					las = trie[las].one_bit;
					trie[las].cnt--;
				}
				else{
					las = trie[las].zero_bit;
					trie[las].cnt--;
				}
			}
			else{
				if(A[i] & pak[j]){
					las = trie[las].zero_bit;
					trie[las].cnt--;
					ans += pak[j];
				}
				else{
					las = trie[las].one_bit;
					trie[las].cnt--;
					ans += pak[j];
				}
			}
		}
		cout << ans << " ";
	}
	cout << "\n";
	return 0;	
}