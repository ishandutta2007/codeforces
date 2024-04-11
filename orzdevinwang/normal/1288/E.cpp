#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 9;
int n, m, s[N], ch[N][2], siz[N], fa[N], key[N], splx, sply, splz, root;
int Ansa[N], Ansb[N];
inline void upd(int now) {
    siz[now] = siz[ch[now][0]] + siz[ch[now][1]] + 1;
    if(ch[now][0]) fa[ch[now][0]] = now;
    if(ch[now][1]) fa[ch[now][1]] = now;
}
inline void split(int now, int k, int &x, int &y) {
    if(!now) return (void)(x = y = 0);
    if(k >= siz[ch[now][0]] + 1) x = now, fa[ch[now][1]] = 0, split(ch[now][1], k - siz[ch[now][0]] - 1, ch[now][1], y);
    else y = now, fa[ch[now][0]] = 0, split(ch[now][0], k, x, ch[now][0]);
    upd(now);
}
inline int gefrk(int now) {
	if(!fa[now]) return 1;
	if(ch[fa[now]][0] == now) return gefrk(fa[now]);
	else return gefrk(fa[now]) + siz[ch[fa[now]][0]] + 1;
}
inline int getrk(int now) {
	return gefrk(now) + siz[ch[now][0]];
}
int merge(int x, int y) {
    if(!x || !y) return x + y;
    if(key[x] < key[y]) return ch[x][1] = merge(ch[x][1], y), upd(x), x;
    else return ch[y][0] = merge(x, ch[y][0]), upd(y), y;
}
int main() {
    srand(1919810);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) 
        siz[i] = 1, key[i] = rand(), root = merge(root, i), Ansa[i] = Ansb[i] = i;
    while(m--) {
    	int pp;
        scanf("%d", &pp);
        int mmm = getrk(pp);
        Ansa[pp] = 1, Ansb[pp] = max(Ansb[pp], mmm);
        split(root, mmm - 1, splx, sply), split(sply, 1, sply, splz);
        root = merge(merge(sply, splx), splz);
    }
    for(int i = 1; i <= n; i++) {
    	printf("%d ", Ansa[i]);
    	printf("%d\n", max(Ansb[i], getrk(i)));
	}
    return 0;
}