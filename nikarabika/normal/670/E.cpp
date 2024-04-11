//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define next nxt
#define prev prv

const int maxn = 5e5 + 85 - 69;
int next[maxn],
	prev[maxn],
	match[maxn];
string s;
int n, m, ptr;
stack<int> stc;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < maxn; i++)
		prev[i] = i - 1, next[i] = i + 1;
	cin >> n >> m >> ptr, ptr--;
	cin >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == '(')
			stc.push(i);
		else
			match[i] = stc.top(), match[stc.top()] = i, stc.pop();
	}
	for(int i = 0; i < m; i++){
		char c;
		cin >> c;
		if(c == 'L')
			ptr = prev[ptr];
		else if(c == 'R')
			ptr = next[ptr];
		else{
			int ptr2 = match[ptr];
			if(s[ptr] == '('){
				prev[next[ptr2]] = prev[ptr];
				if(~prev[ptr]) next[prev[ptr]] = next[ptr2];
				ptr = next[ptr2];
			}
			else{
				prev[next[ptr]] = prev[ptr2];
				if(~prev[ptr2]) next[prev[ptr2]] = next[ptr];
				ptr = next[ptr];
			}
			if(ptr >= n)
				ptr = prev[ptr];
		}
	}
	string ret;
	ptr = n;
	do{
		ptr = prev[ptr];
		if(~ptr) ret += s[ptr];
	}while(~ptr);
	reverse(all(ret));
	cout << ret << endl;
	return 0;
}