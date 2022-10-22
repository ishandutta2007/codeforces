#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1e5 + 5;

int n, suf; char s[N], t[N];
vector<int> b;

void prt(char s[]) {
	vector<int> as;
	rep(i, 1, n) if(s[i] == '#') if(s[i - 1] == '#') as.back()++;
	else as.pb(1);
	cout << as.size() << endl;
	for(int x : as) printf("%d ", x);
	exit(0);
}
void chk(int d) {
    if(d <= 1 || suf < d) return;
    rep(i, 1, n) t[i] = s[i];
    for(int i : b) rep(j, 1, d) if(i - j < 1 || s[i - j - 1] == '#') return;
    else t[i - j] = '#';
    int ls = -1;
    rep(i, 1, n) if(t[i] == '#') {
        if(ls == i - 1) { ls = i; continue; }
        if(i - ls - 1 == 2) return;
        if(i - ls - 1 & 1) for(int j = i - 2; j > ls; j -= 2) t[j] = '#';
        else {
            t[i - 2] = '#';
            for(int j = i - 3; j > ls; j -= 2) t[j] = '#';
        }
        ls = i;
    }
    if(n - d - ls + 1 == 2) return;
    if(n - d - ls + 1 & 1) for(int j = n - d; j > ls; j -= 2) t[j] = '#';
    else {
        t[n - d] = '#';
        for(int j = n - d - 1; j > ls; j -= 2) t[j] = '#';
    }
    prt(t);
}
void chk1() {
    if(suf < 1) return;
    rep(i, 1, n) t[i] = s[i];
    for(int i : b) if(i - 1 < 1 || s[i - 2] == '#') return;
    else t[i - 1] = '#';
    int ls = -1;
    rep(i, 1, n) if(t[i] == '#') {
        if(ls == i - 1) { ls = i; continue; }
        if((i - ls - 1) % 2 == 0) return;
        for(int j = i - 2; j > ls; j -= 2) t[j] = '#';
        ls = i;
    }
    if((n - ls) % 2 == 0) return;
    for(int j = n - 1; j > ls; j -= 2) t[j] = '#';
    prt(t);    
}
void chk0() {
	if(s[1] == '_' || s[n] == '_') return;
	int ls = 0;
	rep(i, 1, n) if(s[i] == '#') {
		if(ls < i - 3) return;
		ls = i;
	}
	prt(s);
}
int main() {
#ifdef local
	freopen(".in", "r", stdin);
#endif
    scanf("%s", s + 1), n = strlen(s + 1);
    rep(i, 1, n) if(s[i] == '#' && s[i - 1] != '#') b.pb(i);
    if(b.empty()) puts("0"), exit(0);
    per(i, n, 1) if(s[i] == '#') { suf = n - i + 1; break; }
    chk0(), chk1(), chk(2), chk(suf);
    int ls = -1, mi = suf;
    rep(i, 1, n) if(s[i] == '#') {
        if(ls == i - 1) { ls = i; continue; }
        mi = min(mi, i - ls - 2), ls = i;
    }
    chk(mi), puts("-1");
}