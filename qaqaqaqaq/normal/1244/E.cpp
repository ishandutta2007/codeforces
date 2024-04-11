#include<bits/stdc++.h>
using namespace std;

const int maxn=100007;
int n,a[maxn];
long long k;
vector<pair<int,int> > val;

int solve(int l,int r,long long k){
	if (l>=r) return 0;
	if (val[l].second>val[r].second){
		if (k>=(long long)(val[r].first-val[r-1].first)*val[r].second){
			val[r-1].second+=val[r].second;
			return solve(l,r-1,k-(long long)(val[r].first-val[r-1].first)*val[r].second);
		}
		else{
			return val[r].first-val[l].first-k/val[r].second;
		}
	}
	else{
		if (k>=(long long)(val[l+1].first-val[l].first)*val[l].second){
			val[l+1].second+=val[l].second;
			return solve(l+1,r,k-(long long)(val[l+1].first-val[l].first)*val[l].second);
		}
		else{
			return val[r].first-val[l].first-k/val[l].second;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for (int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
	int cnt=0;
	for (int i=0;i<n;++i){
		if (i+1<n&&a[i]==a[i+1]){
			cnt++;
			continue;
		}
		val.push_back({a[i],cnt+1});
		cnt=0;
	}
	int l=0,r=val.size()-1;
	cout<<solve(l,r,k)<<endl;
	return 0;
}