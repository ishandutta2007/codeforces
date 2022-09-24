#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

struct Xenia {
    int m, n;
    vector<int>data;
    Xenia(int n) :n(n){
	m = 1;
	for (;m<n;) m*=2;
	data = vector<int>(m*2, 0);
    }
    void push(int p, int v) { push(p, v, 1, m); }
    bool push(int p, int v, int k, int s) {
	if (m<=k) {
	    data[k] = v;
	    return true;
	}
	bool b;
	if (2*p < s) b = push(p, v, k*2, s/2);
	else b = push(p-s/2, v, k*2+1, s/2);

	if (b) data[k] = data[k*2] | data[k*2+1];
	else   data[k] = data[k*2] ^ data[k*2+1];
	return !b;
    }
    int top() { return data[1]; }
};

int N, M;
int main() {


    scanf("%d%d", &N, &M);
    Xenia xenia(1<<N);
    
    for (int i=0; i<(1<<N); i++) {
	int a;
	scanf("%d", &a);
	xenia.push(i, a);
    }
    for (;M--;) {
	int p, b; scanf("%d%d", &p, &b); p--;
	xenia.push(p, b);
	printf("%d\n", xenia.top());
    }
    
    return 0;
}