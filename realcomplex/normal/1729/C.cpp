#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int AL = 26;
vector<int> lis[AL];
int s[N];

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        string t;
        cin >> t;
        int n = t.size();
        for(int i = 0 ; i < AL; i ++ ) lis[i].clear();
        for(int i = 0 ; i < n; i ++ ){
            s[i] = t[i] - 'a';
            lis[s[i]].push_back(i + 1);
        }
        int x = s[0];
        int y = s[n - 1];
        if(x <= y){
            vector<int> soln;
            for(int p = x; p <= y; p ++ ){
                for(auto q : lis[p]) soln.push_back(q);
            }
            cout << y - x << " " << soln.size() << "\n";
            for(auto p : soln) cout << p << " ";
            cout << "\n";
        }
        else{
            vector<int> soln;
            for(int p = x; p >= y; p -- ){
                for(auto q : lis[p]) soln.push_back(q);
            }
            cout << x - y << " " << soln.size() << "\n";
            for(auto p : soln) cout << p << " ";
            cout << "\n";
        }
    }
    return 0;
}