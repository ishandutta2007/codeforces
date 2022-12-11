#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // freopen("in.txt","r",stdin);
    int n;
    cin >> n;
    int k;
    bool is;
    vector<int>ans;
    for(int j = 1;j<=n;j++){
        is = true;
        for(int i = 0;i<n;i++){
            cin >> k;
            if(k == 1 || k == 3) is = false;
        }
        if(is == true)ans.push_back(j);
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    return 0;
}