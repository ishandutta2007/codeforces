#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,t;
    cin >> n >> t;
    int mx = 0;
    int sum = 0;
    int p = 0;
    int sk[n];
    for(int j =0;j<n;j++){
        cin >> sk[j];
        if(sk[j] <= t){
            mx = max(1,mx);
        }
        sum += sk[j];
        if(sum<=t){
            mx = max(mx,j-p+1);
        }
        while(sum>t&&p<j){
            sum-=sk[p];
            p++;
        }
    }
    if(sum<=t){
        mx = max(mx,n-p);
    }
    cout << mx;
    return 0;
}