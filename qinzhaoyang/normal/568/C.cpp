#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back

using namespace std;

void GG() {
	printf("-1\n") , exit(0);
}

const int N = 210 , inf = 0x3f3f3f3f;

char s[N];
int l , n , m , n0[30] , n1[30] , f = 0 , sta[N << 1] , top = 0 , a[N];
vector <int> G[N << 1];

int ch(int x) {return x > n ? x - n : x + n;}

void init() {
	int j = inf , k = inf;
	for(int i = l; i; i--) {
		if(s[i] == 'C') k = i; else j = i;
		n0[i] = j , n1[i] = k;
	}
	n0[l + 1] = n1[l + 1] = inf;
}

int v[N << 1];

int dfs(int x) {
	if(v[ch(x)]) return false;
	if(v[x]) return true;
	v[sta[++top] = x] = 1;
	for(auto i : G[x]) if(!dfs(i))
		return v[x] = 0;
	return 1;
}

int main() {
	scanf("%s" , s + 1) , l = strlen(s + 1);
	init() , scanf("%d%d" , &n , &m);
	for(int i = 1; i <= m; i++) {
		int p1,  p2; char t1 , t2;
		scanf("%d %c%d %c" , &p1 , &t1 , &p2 , &t2);
		if(t1 == 'V') p1 = ch(p1); if(t2 == 'V') p2 = ch(p2);
		G[p1].pb(p2) , G[ch(p2)].pb(ch(p1));
	}
	scanf("%s" , s + 1);
	for(int i = 1; i <= n; i++) a[i] = s[i] - 'a' + 1;
	for(int i = 1; i <= n; i++) {
		top = 0; if(f) a[i] = 1;
		label:;
		if(n0[a[i]] == inf) {
			if(n1[a[i]] == inf || !dfs(i))
				GG();
		}
		else if(n1[a[i]] == inf) {
			if(!dfs(ch(i)))
				GG(); 
		}
		else if(!v[i] && !v[i + n]) {
			if(n0[a[i]] > n1[a[i]]) {
				if(!dfs(i)) {
					f = 1;
					if(!dfs(ch(i)))
						GG();
				}
			}
			else {
				if(!dfs(ch(i))) {
					f = 1;
					if(!dfs(i))
						GG();
				}
			}
		}
		else if(v[i] ? n1[a[i]] > a[i] : n0[a[i]] > a[i])
			f = 1;
		if(!f) {
			for(int j = i + 1; j <= n; j++) {
				if(v[j]) {
					if(n1[a[j]] == inf) {
						f = 1 , a[i]++;
						break;
					}
					else if(n1[a[j] + 1] < inf)
						break;
				}
				else if(v[j + n]) {
					if(n0[a[j]] == inf) {
						f = 1 , a[i]++;
						break;
					}
					else if(n0[a[j] + 1] < inf)
						break;
				}
				else if(n0[a[j] + 1] < inf || n1[a[j] + 1] < inf)
					break;
			}
			if(f) {
				while(top) v[sta[top--]] = 0;
				goto label;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		putchar(char('a' - 1 + (v[i] ? n1[a[i]] : n0[a[i]])));
	putchar('\n');
	return 0;
}