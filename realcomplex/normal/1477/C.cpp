#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5010;
bool use[N];
ll xi[N];
ll yi[N];


int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i =0  ;i < n; i ++ ){
        cin >> xi[i] >> yi[i];
    }
    vector<int> ord;
    ord.push_back(0);
    use[0]=true;
    int las = 0;
    int nx;
    ll sum;
    ll cur;
    for(int i = 1; i < n; i ++ ){
        nx = -1;
        sum = 0;
        cur = 0;
        for(int j = 0 ; j < n ; j ++ ){
            if(use[j]) continue;
            cur = (xi[j]-xi[las])*1ll*(xi[j]-xi[las]) + (yi[j]-yi[las])*1ll*(yi[j]-yi[las]);
            if(cur > sum){
                sum = cur;
                nx = j;
            }
        }
        ord.push_back(nx);
        use[nx]=true;
        las=nx;
    }
    for(auto q : ord){
        cout << q + 1 << " ";
    }
    cout << "\n";
    return 0;
}