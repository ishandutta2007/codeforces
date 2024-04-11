#include <stdio.h>

#define MX_N 1000010

int tree[MX_N];
int tmp[MX_N];
int arr[MX_N];
int out[MX_N];
int n,m,mx;
int l = 1;

void update(int idx,int val) {
	while(idx <= n) {
		tree[idx] += val;
		idx += idx & (-idx);
	}
}
int query(int idx) {
	int ans = 0;
	while(idx > 0) {
		ans += tree[idx];
		idx -= idx & (-idx);
	}
	return ans;
}
int search(int val) {
	int a = 1,b = l-1;
	while(a < b) {
		int m = (a+b)/2;
		int r = query(m);
		if(r >= val) b = m;
		else a = m+1;
	}
	return b;
}
int main() {
	int i,j;
	scanf("%d %d",&n,&m);
	for(mx=1;2*mx <= n;)
		mx <<= 1;
	for(i=0;i<m;i++) {
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		if(a == -1) {
			int s = query(l-1);
			for(j=0;j<m && arr[j] <= s;j++) {
				tmp[j] = search(arr[j]);
			}
			while(--j >= 0) {
				update(tmp[j],-1);
			}
		}else {
			out[l] = a;
			update(l++,1);
		}
	}
	if(query(n) == 0) {
		printf("Poor stack!\n");
	}else {
		int a,b = 0;
		for(j=1;j<=l;j++) {
			a = query(j);
			if(a - b == 1)
				printf("%d",out[j]);
			b = a;
		}
		printf("\n");
	}
	return 0;
}