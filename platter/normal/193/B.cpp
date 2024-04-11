#include <bits/stdc++.h>
using namespace std;

struct Node {
	int arr[30];
};

long long ret=-1e18;
int n,u,r;
int a[30];
int b[30];
long long k[30];
int p[30];

void getans(int dep,Node before,int did) {
    Node temp;
	for(int i=0;i<n;i++) {
		if (did==1) {
			temp.arr[i]=before.arr[p[i]]+r;
		}
		else {
			temp.arr[i]=before.arr[i]^b[i];
		}
	}
	if (dep%2==u%2) {
		long long val=0;
		for(int i=0;i<n;i++) {
			val+=k[i]*temp.arr[i];
		}
		ret=max(ret,val);
	}
	if (dep!=u) {
		if (did!=0) {
			getans(dep+1,temp,0);
		}
		getans(dep+1,temp,1);
	}
}

int main(void) {
	scanf("%d %d %d\n",&n,&u,&r);
	for(int i=0;i<n;i++) {
		scanf("%d ",&a[i]);
	}
	for(int i=0;i<n;i++) {
		scanf("%d ",&b[i]);
	}
	for(int i=0;i<n;i++) {
		scanf("%lld ",&k[i]);
	}
	for(int i=0;i<n;i++) {
		scanf("%d ",&p[i]);
		p[i]--;
	}
	Node temp;
	for(int i=0;i<n;i++) {
		temp.arr[i]=a[i];
	}
	long long val=0;
	for(int i=0;i<n;i++) {
		val+=k[i]*temp.arr[i];
	}
	if (u%2==0) {
		ret=max(ret,val);
	}
	getans(1,temp,0);
	getans(1,temp,1);
	printf("%lld",ret);
}