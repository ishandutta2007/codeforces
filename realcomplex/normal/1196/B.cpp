#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int tt = 0; tt < tc; tt ++ ){
        int n, k;
        cin >> n >> k;
        int cnt = 0;
        vector<int> a;
        int p;
        for(int i = 0 ;i  < n; i ++ ){
            cin >> p;
            p%=2;
            a.push_back(p);
            cnt += p;
        }
        if(cnt < k || (cnt - k) % 2 == 1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            vector<int> ans;
            for(int i = 0; i < n; i ++ ){
                if(a[i]){
                    cnt -= 1;
                    if(cnt < k)
                        ans.push_back(i+1);
                }
            }
            if(!ans.empty())ans.pop_back();
            ans.push_back(n);
            for(auto p : ans)
                cout << p << " ";
            cout << "\n";
        }
    }
    return 0;
}