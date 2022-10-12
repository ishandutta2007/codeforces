#include <cstdio>

const int N = 500;

class Stack {
	int a[N];
	public :

	int size;
	Stack () { size = 0; }
	
	void push (int x) {
		a[size++] = x;		
	}
	
	int pop () {
		return a[--size];
	}
	
	int top () {
		return a[size - 1];
	}
	
} stack[N];

int main () {
	int n, k;
	
	scanf ("%d %d", &n, &k);

	int num = n * n;
	int ans = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n-k+1; j++)
			stack[i].push (num--);
		ans += stack[i].top();
	}
	
	for (int i=0; i<n; i++) 
		for (int j=0; j<k-1; j++) 
			stack[i].push (num--);
		
	printf ("%d\n", ans);
	for (int i=0; i<n; i++) {
		while (stack[i].size) printf ("%d ", stack[i].pop());
		printf ("\n");
	}
}