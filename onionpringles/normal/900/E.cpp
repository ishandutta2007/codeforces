#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
char str[N];
int cnt[N];
set<int> S[2][2];
typedef pair<int,int> pii;
pii dp[N];
int main(){
	int n;scanf("%d %s",&n,str);
	int m;scanf("%d",&m);
	for(int i=0;i<n;i++){
		cnt[i+1]=cnt[i];
		if(str[i]=='?')cnt[i+1]++;
	}
	for(int i=0;i<n;i++){
		if(str[i]=='?')continue;
		S[str[i]-'a'][i%2].insert(i);
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(i>=m){
			bool bad=false;
			int s=i-m;s=s%2;
			auto it = S[0][s^1].lower_bound(i);
			if(it!=S[0][s^1].begin()){
				it--;
				if(*it >=i-m)bad=true;
			}
			it=S[1][s].lower_bound(i);
			if(it!=S[1][s].begin()){
				it--;
				if(*it>=i-m)bad=true;
			}
			if(!bad){
				dp[i]=max(dp[i],pii(dp[i-m].first+1,dp[i-m].second-cnt[i]+cnt[i-m]));
			}
		}
	}
	printf("%d\n",-dp[n].second);
}