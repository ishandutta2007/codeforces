#include <bits/stdc++.h>
#define pii pair<int,int>
#define pip pair<int,pii>
#define maxn 400400
#define debug 
#define pb push_back
typedef long long ll;
using namespace std;

int l[maxn];
int r[maxn];
int L[maxn];
int R[maxn];
int ans[maxn];

int main(){

	vector<pii> a;
	
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",l+i);
	for(int i=0;i<n;i++) scanf("%d",r+i);
	for(int i=0;i<n;i++)
		a.pb(pii(l[i]+r[i],i));
	sort(a.begin(),a.end());
	//reverse(a.begin(), a.end());
	
	ans[a[0].second] = n;
	
	for(int i=1;i<n;i++){
		ans[a[i].second] = ans[a[i-1].second];
		if(a[i].first > a[i-1].first)
			ans[a[i].second]--;
	}
	int ok = 1;
	for(int i=0;i<n;i++){
	
		for(int j=0;j<i;j++)
			if(ans[j] > ans[i]) L[i]++;
		for(int j=i+1;j<n;j++)
			if(ans[j] > ans[i]) R[i]++;
			
		if(L[i] != l[i] || R[i] != r[i]) ok = 0;
		debug("%d %d\n",L[i],R[i]);
	}
	//ok = 1;
	if(!ok)
		printf("NO\n");
	else {
		printf("YES\n");
		for(int i=0;i<n;i++)
			printf("%d ",ans[i]);
	}
	
}