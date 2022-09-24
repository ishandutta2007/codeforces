#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


typedef long long LL;

int N, M;
LL a[100010];

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) cin>>a[i];
    scanf("%d", &M);

    int p=0;
    for (int i=0; i<M; i++) {
	int w; LL h;
	cin>>w>>h;
	w--;
	if (p<w) {
	    a[w]=max(a[w], a[p]);
	    p=w;
	}
	cout<<a[p]<<endl;
	a[p]+=h;
    }

    return 0;
}