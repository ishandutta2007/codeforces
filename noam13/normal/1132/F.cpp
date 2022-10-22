#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
#define chkmax(a,b) (a=max(a,b))
#define chkmin(a,b) (a=min(a,b))
#define INFI 9e18
using namespace std;
#define MAXN 501

vector<vi > dp(MAXN,vi(MAXN,-1));
string s;
int solve(int l,int r){
    if (l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    if (l==r) {dp[l][r]=1; return 1;}
    
    int cur=solve(l+1,r)+1;
    for(int i=l+1;i<=r;i++){
        if(s[i]==s[l]) chkmin(cur,solve(l+1,i-1)+solve(i,r));
    }
    dp[l][r]=cur;
    return cur;
}
int main(){
    int n;
    cin >> n >>s;
    n=s.length();
    cout <<solve(0,n-1)<<endl;
}