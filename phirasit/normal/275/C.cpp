#include <stdio.h>
#include <algorithm>
#include <vector>
#define MX_N 100010

using namespace std;

vector<int> v[MX_N];
int arr[MX_N];
int side[MX_N];
int n,k;

int search(int val) {
	int a,b,m;
	a = 0; b = n-1;
	while(a<=b) {
		int m = (a+b)/2;
		if(arr[m] == val) return m;
		if(arr[m] < val) a = m+1;
		else b = m-1;
	}
	return -1;
}
void set(int i,int t) {
	if(side[i] >= 0) return;
	side[i] = t;
	int s = v[i].size();
	for(int j=0;j<s;j++)
		set(v[i][j],!t);
}
int main() {
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	for(i=0;i<n;i++) {
		if(arr[i]%k == 0) {
			if((j=search(arr[i]/k)) >= 0) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
		side[i] = -1;
	}
	for(i=0;i<n;i++) {
		if(side[i] < 0) {
			set(i,1);
		}
	}
	int ans = 0;
	for(i=0;i<n;i++)
		if(side[i] == 0)
			ans++;
	if(n-ans > ans) printf("%d\n",n-ans);
	else printf("%d\n",ans);
	return 0;
}