#include <iostream>
#include <set>

using namespace std;

int n;
int p[303030];
int w[303030];
int q[303030];

#define N (1<<19)
int t[2][2*N];

void setVal(int w, int k) {
	k += N;
	t[w][k] = 1;
	for (k /= 2; k >= 1; k /= 2) {
		t[w][k] = t[w][2*k]+t[w][2*k+1];
	}
}

int getSum(int w, int a, int b) {
	a += N; b += N;
	int s = 0;
	while (a <= b) {
		if (a%2 == 1) s += t[w][a++];
		if (b%2 == 0) s += t[w][b--];
		a /= 2; b /= 2;
	}
	return s;
}

int r[2*N][2];

void incPre(int k, int x) {
	k += N;
	r[k][0] += x;
	r[k][1] = max(0,r[k][0]);
	for (k /= 2; k >= 1; k /= 2) {
		r[k][0] = r[2*k][0]+r[2*k+1][0];
		r[k][1] = max(r[2*k][1],r[2*k][0]+r[2*k+1][1]);
	}
}

int preSum(int k) {
	int a = 1+N;
	int b = k+N;
	int s = 0;
	while (a <= b) {
		if (a%2 == 1) s += r[a++][0];
		if (b%2 == 0) s += r[b--][0];
		a /= 2; b /= 2;
	}
	return s;
}

int findSum(int p, int a, int b, int k, int s) {
	if (a > k) return 0;
	int w = (b-a+1)/2;
	if (b > k) return max(findSum(2*p,a,a+w-1,k,s),
	                      findSum(2*p+1,a+w,b,k,s+r[2*p][0]));
	else return s+r[p][1];
}

int maxSum(int k) {
	return findSum(1,0,N-1,k,0);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		w[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> q[i];
	}
	int c = 0;
	for (int i = n; i >= 1; i--) {
		while (true) {
			int s = getSum(0,w[i],n)-getSum(1,w[i],n);
			int pp = maxSum(w[i]-1)-preSum(w[i]-1);
			if (pp > 0) s -= pp;
			if (s <= 0 && c <= n-1) {
				cout << i << " ";
				c++;
				setVal(0,q[c]);
				incPre(q[c],1);
			} else {
				setVal(1,w[i]);
				incPre(w[i],-1);
				break;
			}
		}
	}
	cout << "\n";
}