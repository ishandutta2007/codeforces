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
#define len(x) ((int)(x).size())

const int N = (int)2e5 + 9;
const int BLOCK_SIZE =(int)(sqrt(N) + 1);
const int H = 128;

set<int>P[H];
int chars[BLOCK_SIZE];
char st[N];

int search(int x){
	int p = 0,tot = 0,ix = 0;
	while(tot + chars[p] <= x){
		tot += chars[p];
		ix += BLOCK_SIZE;
		p++;
	}
	while(tot + (st[ix] != '+') <= x){
		tot += (st[ix] != '+');
		ix++;
	}
	return ix;
}

int main(){
	fastIO;
	int n,q;
	cin >> n >> q;
	for(int i = 0;i<n;i++){
		cin >> st[i];
		P[st[i]].insert(i);
		chars[i/BLOCK_SIZE]++;
	}
	int l,r;
	char cur;
	while(q--){
		cin >> l >> r >> cur;
		--l;
		--r;
		l=search(l);
		r=search(r);
		while(1){
			auto x = P[cur].lower_bound(l);
			if(x == P[cur].end())
				break;
			if((*x) > r)
				break;
			chars[(*x)/BLOCK_SIZE]--;
			st[(*x)] = '+';
			P[cur].erase(x);
		}
	}	
	for(int i = 0;i<n;i++)
		if(st[i] != '+')
			cout << st[i];
	return 0;
}