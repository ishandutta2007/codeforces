#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

int n, ansx1, ansy1, ansx2, ansy2;
int main() {
	scanf("%d", &n);
	for(int i=1, x; i<n; ++i){
		printf("? %d %d %d %d\n", 1, 1, i, n);
		fflush(stdout);
		scanf("%d", &x);
		if(x&1){
			if(!ansx1) ansx1=i;
			ansx2=i+1;
		}
	}
	for(int i=1, x; i<n; ++i){
		printf("? %d %d %d %d\n", 1, 1, n, i);
		fflush(stdout);
		scanf("%d", &x);
		if(x&1){
			if(!ansy1) ansy1=i;
			ansy2=i+1;
		}
	}
	if(ansx1 && ansy1){
		printf("? %d %d %d %d\n", ansx1, ansy1, ansx1, ansy1);
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if(x==1) printf("! %d %d %d %d\n", ansx1, ansy1, ansx2, ansy2);
		else printf("! %d %d %d %d\n", ansx1, ansy2, ansx2, ansy1);
		fflush(stdout);
	}
	else if(ansx1){
		int l=1, r=n, ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			printf("? %d %d %d %d\n", ansx1, 1, ansx1, mid);
			fflush(stdout);
			int x;
			scanf("%d", &x);
			if(x&1) r=mid-1, ans=mid; else l=mid+1;
		}
		printf("! %d %d %d %d\n", ansx1, ans, ansx2, ans);
		fflush(stdout);
	}
	else{
		int l=1, r=n, ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			printf("? %d %d %d %d\n", 1, ansy1, mid, ansy1);
			fflush(stdout);
			int x;
			scanf("%d", &x);
			if(x&1) r=mid-1, ans=mid; else l=mid+1;
		}
		printf("! %d %d %d %d\n", ans, ansy1, ans, ansy2);
		fflush(stdout);
	}
	return 0;
}