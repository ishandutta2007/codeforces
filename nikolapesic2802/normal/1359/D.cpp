#include<bits/stdc++.h>
using namespace std;

#define rep(i, st, en) for(int i=st; i<=en; i++)


const int N = 1e5 + 5;
int a[N], mxl[N], mxr[N], pref[N], suff[N];

int preprocess(int n){
    stack<int> s;
    for(int i=1; i<=n; i++){
        while(s.size() && a[s.top()] < a[i]){
            int z = s.top();
            mxl[i] = max(mxl[i], a[z] + mxl[z] + pref[i - 1] - pref[z]);
            s.pop();
        }
        s.push(i);
        pref[i] = pref[i - 1] + a[i];
    }

    while(s.size()) s.pop();

    for(int i=n; i>=1; i--){
        while(s.size() && a[s.top()] <= a[i]) {
            int z = s.top();
            mxr[i] = max(mxr[i], a[z] + mxr[z] + suff[i + 1] - suff[z]);
            s.pop();
        }
        s.push(i);
        suff[i] = suff[i + 1] + a[i];
    }

    int ans = 0;
    rep(i, 1, n){
        ans = max(ans,mxl[i]+mxr[i]);
    }

    return ans;

}



void solve(){
    int n;
    cin>>n;
    rep(i, 1, n) cin>>a[i];

    cout<<preprocess(n)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    //  cin>>t;
    while(t--){
        solve();
    }

    return 0;
}