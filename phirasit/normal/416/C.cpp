#include <stdio.h>
#include <algorithm>
#include <vector>

#define N 1010

#define A first
#define B second

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> p3;

p3 arr[N];
pii T[N];
int pass[N];
int n,m;

int cmp(p3 a,p3 b) {
	return a.A.B > b.A.B;
}
int cmp2(pii a,pii b) {
	return a.B < b.B;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&arr[i].A.A,&arr[i].A.B);
		arr[i].B = i;
	}
	sort(arr+1,arr+n+1,cmp);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		scanf("%d",&T[i].A);
		T[i].B = i;
	}
	sort(T + 1,T + m+1);
	vector<pii> V;
	int ans = 0;
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++) {
			if(pass[j]) continue;
			if(arr[j].A.A <= T[i].A) {
				ans += arr[j].A.B;
				V.push_back(make_pair(arr[j].B,T[i].B));
				pass[j] = 1;
				break;
			}
		}
	}
	sort(V.begin(),V.end(),cmp2);
	printf("%d %d\n",V.size(),ans);
	for(int i=0;i<V.size();i++) {
		printf("%d %d\n",V[i].A,V[i].B);
	}
	return 0;
}