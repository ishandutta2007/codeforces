#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e4 + 10;
char dp[26][maxn*25];
int a[maxn];
int main()
{
	int n; cin>>n;
	n *= 2;
	int sum = 0, num = (n-2)/2;
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]), sum += a[i];
	sort(a,a+n);
	sum -= a[0] + a[1];
	int fix = sum/2;
	//cout<<"fix:"<<fix<<endl;
	dp[0][0] = -1;
	int up = 0;
	for(int i = 2; i < n; ++i){
        for(int k = min(i-2,num-1); k >= 0; --k){
            for(int j = min(up, fix-a[i]); j >= 0; --j){
                if(dp[k][j] && !dp[k+1][j+a[i]] ) {
                    dp[k+1][j+a[i]] = i;
                }
            }
        }
        up += a[i];
	}

	int ans;
	for(int i = fix; i >= 0; --i){
        if(dp[num][i]) {
            ans = i; break;
        }
	}
	int vis[55]; memset(vis, 0, sizeof vis);
	int id = dp[num][ans];
	while(id != -1){
        vis[id] = 1;
        num--; ans -= a[id];
        id = dp[num][ans];
	}
	cout<<a[0];
	for(int i = 2; i < n; ++i) if(vis[i]) cout<<" "<<a[i]; cout<<endl;
	for(int i = n-1; i >= 2; --i){
        if(!vis[i]) cout<<a[i]<<" ";
	}cout<<a[1]<<endl;
	//cout<<"?"<<endl;
	return 0;
}