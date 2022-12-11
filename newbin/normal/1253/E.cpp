#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 50;
int dp[maxn];
int n, m;
struct node{
    int x, r;
    bool operator < (const node& a) const{return x < a.x;}
}e[100];
int main()
{
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
	cin>>n>>m;
	for(int i = 0; i < n; ++i) scanf("%d%d", &e[i].x, &e[i].r);
	sort(e, e+n);
	for(int i = 0; i < n; ++i){
        for(int j = 0; j + e[i].x + e[i].r <= 2*m; ++j){
            int pre = e[i].x - e[i].r - j - 1;
            if(pre < 0) pre = 0;
            dp[e[i].x + e[i].r + j] = min(dp[e[i].x + e[i].r + j], dp[pre] + j);
        }
        for(int j = 2*m-1; j >= 0; --j) dp[j] = min(dp[j], dp[j+1]);
	}
	cout<<dp[m]<<endl;
}