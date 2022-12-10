#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;

#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 69;
pie heap[maxn];
const LL base = 37, D = 1e9 + 7;
LL P[maxn], hash[maxn];
int k, n;
string s;

LL H(int l, int r){
	return (l == 0) ? hash[r] : (((hash[r] - hash[l - 1] * P[r - l + 1]) % D) + D) % D;
}

bool cmp(pie x, pie y){
	if(x.R == s.size())
		return false;
	if(y.R == s.size())
		return true;
	int xs = x.R - x.L + 1, ys = y.R - y.L + 1;
	int lo = 0, hi = min(xs, ys) + 1;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		LL xh = H(x.L, x.L + mid - 1);
		LL yh = H(y.L, y.L + mid - 1);
		if(xh == yh)
			lo = mid;
		else
			hi = mid;
	}
	if(lo == min(xs, ys))
		return xs < ys;
	return s[x.L + lo] < s[y.L + lo];
}

void fixdtu(int id){
	if(id == 1)
		return;
	if(cmp(heap[id], heap[id / 2])){
		swap(heap[id], heap[id / 2]);
		fixdtu(id / 2);
	}
}

void fixutd(int id = 1){
	if(id * 2 + 1 < n){
		if(cmp(heap[id * 2 + 0], heap[id * 2 + 1]) and !cmp(heap[id], heap[id * 2 + 0])){
			swap(heap[id], heap[id * 2 + 0]);
			fixutd(id * 2 + 0);
		}
		else if(!cmp(heap[id], heap[id * 2 + 1])){
			swap(heap[id], heap[id * 2 + 1]);
			fixutd(id * 2 + 1);
		}
		return;
	}
	if(id * 2 + 0 < n and !cmp(heap[id], heap[id * 2 + 0])){
		swap(heap[id], heap[id * 2 + 0]);
		fixutd(id * 2 + 0);
	}
}

void Insert(pie x){
	heap[n] = x;
	fixdtu(n++);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> k;
	hash[0] = s[0] - 'a' + 1;
	P[0] = 1;
	for(int i = 1; i < s.size(); i++)
		hash[i] = (hash[i - 1] * base + s[i] - 'a' + 1) % D;
	for(int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] * base) % D;
	//int fi, se, th, fo;
	//while(cin >> fi >> se >> th >> fo)
	//	cout << cmp(MP(fi, se), MP(th, fo)) << endl;
	n = 1;
	for(int i = 0; i < s.size(); i++)
		Insert(MP(i, i));
	while(k--){
		if(heap[1].R == s.size()){
			cout << "No such line." << endl;
			return 0;
		}
		if(k == 0){
			cout << s.substr(heap[1].L, heap[1].R - heap[1].L + 1) << endl;
			return 0;
		}
		heap[1].R++;
		fixutd();
	}
	return 0;
}