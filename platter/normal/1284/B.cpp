#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
 
int INF=1e9;
vector<int> mini;
vector<int> maxi;
int n;
int l;
 
int search(int x) {
	int lo=0;
	int hi=l;
	int mid=(lo+hi)/2;
	if (maxi[1]<=x) {
	    return 0;
	}
	if (maxi[l]>x) {
	    return l;
	}
	while (lo<=hi) {
		mid=(lo+hi)/2;
		if (maxi[mid]>x&&maxi[mid+1]<=x) {
			return mid;
		}
		if (maxi[mid]<=x) {
			hi=mid-1;
		}
		else {
			lo=mid+1;
		}
	}
	return mid;
}
 
bool comp(int a,int b) {
    return a>b;
}
 
int main() {
	scanf("%d\n",&n);
	l=n;
	for(int i=0;i<n;i++) {
		int x;
		scanf("%d",&x);
		int mn=INF;
		int mx=0;
		bool flag=true;
		for(int j=0;j<x;j++) {
			int k;
			scanf("%d ",&k);
			if (k>mn) {
			    flag=false;
			}
			mn=min(mn,k);
			mx=max(mx,k);
		}
		if (flag) {
		    mini.push_back(mn);
		    maxi.push_back(mx);
		}
		else {
		    l--;
		}
		scanf("\n");
	}
	maxi.push_back(-INF);
	maxi.push_back(INF);
	sort(maxi.begin(),maxi.end(),comp);
	long long minus=n-l;
	long long plus=n+l;
	long long ret=minus*plus;
	for(int i=0;i<l;i++) {
		ret+=search(mini[i]);
	}
	printf("%lld",ret);
	return 0;
}