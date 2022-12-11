#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int main(){
    fastIO;
    int n, k;
    cin >> n >> k;
    vector<int> both, al, bb;
    int ans = (int)2e9 + 100;
    int t, a, b;
    for(int i = 0 ; i < n; i ++ ){
        cin >> t >> a >> b;
        if(a == 1 && b == 1){
            both.push_back(t);
        }
        else if(a == 1){
            al.push_back(t);
        }
        else if(b == 1){
            bb.push_back(t);
        }
    }
    sort(both.begin(), both.end());
    sort(al.begin(), al.end());
    sort(bb.begin(), bb.end());
    for(int i = 1; i < al.size(); i ++ ) al[i] += al[i - 1];
    for(int i = 1; i < bb.size(); i ++ ) bb[i] += bb[i - 1];
    int com = 0;
    for(int i = 0 ; i <= both.size(); i ++ ){
        if(i > k) continue;
        if(i > 0)com += both[i - 1];
        if(k - i > al.size() || k - i > bb.size()) continue;
        if(i < k)ans = min(ans, com + al[k - i - 1] + bb[k - i - 1]);
        else ans = min(ans, com);
    }
    if(ans == (int)2e9 + 100)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}