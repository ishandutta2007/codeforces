#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair
#define MAXN 2000

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int>ans;
    bitset<2000>val;
    int k;
    for(int j = 2;j<=n;j++){
        if(val[j] == 0){
            k = j*2;
            while(k<=n){
                val[k] = 1;
                k+=j;
            }
            k = j;
            while(k<=n){
                ans.push_back(k);
                k*=j;
            }
        }
    }
    cout << ans.size() << "\n";
    for(int j = 0;j<ans.size();j++){
        cout << ans[j] << " ";
    }

    return 0;
}