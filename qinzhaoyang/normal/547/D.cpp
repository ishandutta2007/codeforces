#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

struct Edge {int nxt , to;} e[N << 3];
int first[N << 3] , cur = 1 , f[N << 3];
void con(int x , int y) {e[++cur] = (Edge){first[x] , y} , first[x] = cur;}

int n , d[N << 3] , A[N << 3];
stack <pair<int,int> > s; 

int fa[N << 3];
int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= 400000; i++) fa[i] = i;
	for(int i = 1 , x , y; i <= n; i++) {
		cin >> x >> y , y += 200000;
		d[x]++ , d[y]++;
		con(x , y) , con(y , x);
		if(find(x) != find(y)) fa[fa[x]] = fa[y];
	}
	for(int i = 1; i <= 400000; i++)
		if(d[i] & 1) con(i , 0) , con(0 , i) , fa[find(i)] = find(0) , d[0]++;
	for(int i = 0; i <= 400000; i++)
		if(find(i) == i && d[i])
			s.push(make_pair(i , 0));
	while(!s.empty()) {
		int &fir = first[s.top().first];
		while(f[fir]) fir = e[fir].nxt;
		if(!fir) A[s.top().second >> 1] = (s.top().second & 1) , s.pop();
		else s.push(make_pair(e[fir].to , fir)) , f[fir] = f[fir ^ 1] = 1 , fir = e[fir].nxt;
	}
	for(int i = 1; i <= n; i++) cout << char(A[i] ? 'b' : 'r');
	cout << endl;
	return 0;
}