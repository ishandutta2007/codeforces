#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;


struct D {
    int l, r, i;
};
bool operator<(const D &a, const D&b) {
    return a.l!=b.l?a.l<b.l:a.r>b.r;
}

int main() {
    int n;
    vector<D>v;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
	int l, r;
	cin>>l>>r;
	v.push_back((D){l,r,i+1});
    }
    sort(v.begin(), v.end());
    bool ok=1;
    for (int i=1; i<n; i++) {
	if (v[0].l>v[i].l || v[i].r>v[0].r) ok=0;
    }
    if (ok) printf("%d\n", v[0].i);
    else puts("-1");
    return 0;
}