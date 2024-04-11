#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> t(n+1),d(n+1),p(n+1);
	vector<pair<int,int>> pr;
	for(int i=1;i<=n;i++){cin >> t[i] >> d[i] >> p[i];}
	for(int i=1;i<=n;i++){
		pr.push_back(make_pair(d[i],i));
	}
	sort(pr.begin(),pr.end());
	int dp[128][2048]={0},rv[128][2048]={0};
	for(int i=0;i<n;i++){
		int pt=pr[i].second;
		for(int j=d[pt]-t[pt]-1;j>=0;j--){
				if(dp[i+1][j+t[pt]]<dp[i][j]+p[pt]){
					dp[i+1][j+t[pt]]=dp[i][j]+p[pt];
					rv[i+1][j+t[pt]]=pt;
				}
		}
		for(int j=2047;j>=0;j--){
			if(dp[i+1][j]<dp[i][j]){
				dp[i+1][j]=dp[i][j];
				rv[i+1][j]=0;
			}
		}
	}
	int cl=0,ct=n;
	for(int i=0;i<2048;i++){
			if(dp[ct][cl]<dp[ct][i]){
				cl=i;
			}
	}
	cout << dp[ct][cl] << '\n';
	vector<int> res;
	while(ct>0){
		//printf("%d %d\n",ct,cl);
		if(rv[ct][cl]){
			res.push_back(rv[ct][cl]);
			cl-=t[rv[ct][cl]];
		}
		ct--;
	}
	cout << res.size() << '\n';
	reverse(res.begin(),res.end());
	int fl=0;
	for(auto nx: res){
		if(fl){cout << ' ';}
		cout << nx;fl=1;
	}
	cout << '\n';
	return 0;
}