#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


typedef long long LL;

int n;
int f[1010][1010], row[1010], col[1010];
int cntr[1010], cntc[1010], fixc;
int K;
bool row_cmp(int a, int b) {
    return cntr[a]!=cntr[b]?cntr[a]<cntr[b]:a<b;
}
bool col_cmp(int a, int b) {
    if (f[K][a]!=f[K][b]) return f[K][a]>f[K][b];
    return cntc[a]!=cntc[b]?cntc[a]>cntc[b]:a<b;
}

void show() {
    for (int i=0; i<n; i++) {
	for (int j=0; j<n; j++) {
	    printf("%d", f[row[i]][col[j]]);
	}
	puts("");
    }
}
void shw() {
    vector<int>T, I, J;
    int tmp;
    for (int i=0; i<n; i++) {
	tmp=row[i];
	if (tmp!=i) {
	    T.push_back(1);
	    I.push_back(i);
	    J.push_back(tmp);
	    swap(row[i], row[tmp]);
	    i--;
	}
    }
    for (int i=0; i<n; i++) {
	tmp=col[i];
	if (tmp!=i) {
	    T.push_back(2);
	    I.push_back(i);
	    J.push_back(tmp);
	    swap(col[i], col[tmp]);
	    i--;
	}
    }
    tmp=T.size();
    printf("%d\n", tmp);
    for (int i=tmp; i--;) {
	printf("%d %d %d\n", T[i], I[i]+1, J[i]+1);
    }
}
int main() {
    scanf("%d", &n);

    for (int i=1; i<n; i++) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	f[x][y]=1;
	cntr[x]++; cntc[y]++;
    }
    for (int i=0; i<n; i++) row[i]=col[i]=i;
    
    sort(row, row+n, row_cmp);
    for (int i=1; i<n; i++) {
	if (cntr[row[i]]==0) continue;
	vector<int>v;
	K=row[i] ; sort(col+fixc, col+n, col_cmp);
	for (int j=fixc; j<n; j++) if (f[row[i]][col[j]]) fixc++;

    }
    //show(); puts("");
    shw();
    return 0;
}