#include <cstdio>

int arr[100000][2];

int main(void) {
    int n,q;
    scanf("%d %d\n",&n,&q);
    for(int i=0;i<n;i++) {
    	arr[i][0]=0;
    	arr[i][1]=0;
    }
    int cnt=0;
    for(int i=0;i<q;i++) {
    	int b,a;
    	scanf("%d %d\n",&b,&a);
    	a--;
    	b--;
    	int t=0;
    	if (a==0) {
    		t+=arr[0][1-b];
    		t+=arr[1][1-b];
    	}
    	else if (a==n-1) {
    		t+=arr[n-2][1-b];
    		t+=arr[n-1][1-b];
    	}
    	else {
    		t+=arr[a-1][1-b];
    		t+=arr[a][1-b];
    		t+=arr[a+1][1-b];
    	}
    	if (arr[a][b]==0) {
    		cnt+=t;
    	}
    	else {
    		cnt-=t;
    	}
    	arr[a][b]=1-arr[a][b];
    	if (cnt==0) {
    		printf("Yes\n");
    	}
    	else {
    		printf("No\n");
    	}
    }
    return 0;
}