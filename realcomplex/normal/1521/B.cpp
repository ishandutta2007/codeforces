#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct op{
    int i;
    int j;
    int xx;
    int yy;
};

const int N = (int)1e5 + 10;
int A[N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<op> st;
        int idx = 1;
        for(int i = 1; i <= n; i ++ ){
            cin >> A[i];
            if(A[i] < A[idx]){
                idx = i;
            }
        }
        int dist;
        for(int j = 1; j <= n; j ++ ){
            if(j == idx) continue;
            dist = abs(j - idx);
            st.push_back({j, idx,A[idx] + dist,A[idx]});
        }
        cout << st.size() << "\n";
        for(auto x : st)
            cout << x.i << " " << x.j << " " << x.xx << " " << x.yy << "\n";

    }
    return 0;
}