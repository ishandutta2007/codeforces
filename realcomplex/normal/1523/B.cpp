#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


struct query{
    int type;
    int ii;
    int jj;
};

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        int x;
        vector<query> qq;
        for(int i = 1; i <= n; i ++ ){
            cin >> x;
        }
        for(int i = 1; i <= n; i += 2){
            qq.push_back({1, i, i + 1});
            qq.push_back({2, i, i + 1});
            qq.push_back({1, i, i + 1});
            qq.push_back({1, i, i + 1});
            qq.push_back({2, i, i + 1});
            qq.push_back({1, i, i + 1});
        }
        cout << qq.size() << "\n";
        for(auto x : qq){
            cout << x.type << " " << x.ii << " " << x.jj << "\n";
        }
    }
    return 0;
}