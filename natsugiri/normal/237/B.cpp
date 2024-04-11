#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


int a[55][55], c[55], n, s;
int w[99999], cnt;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", c+i), s+=c[i];
    vector<pair<int,int> >v(s);
    for (int i=0; i<n; i++) {
	for (int j=0; j<c[i]; j++) {
	    scanf("%d", &a[i][j]);
	    a[i][j]--;
	    v[a[i][j]]=make_pair(i, j);
	}
    }
    int p=0;
    cnt=0;
    for (int i=0; i<n; i++) {
	for (int j=0; j<c[i]; j++) {
	    if (a[i][j]!=p) {
		int t=a[i][j];
		w[cnt++]=i+1;
		w[cnt++]=j+1;
		w[cnt++]=v[p].first+1;
		w[cnt++]=v[p].second+1;
		swap(a[i][j], a[v[p].first][v[p].second]);
		swap(v[t], v[p]);
	    }
	    p++;
	}
    }
    printf("%d\n", cnt/4);
    for (int i=0; i<cnt; i+=4) {
	printf("%d %d %d %d\n", w[i], w[i+1], w[i+2], w[i+3]);
    }

    return 0;
}