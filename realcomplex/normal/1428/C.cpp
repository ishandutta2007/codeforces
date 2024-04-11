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
    for(int t = 1; t <= tc; t ++ ){
        string s;
        cin >> s;
        vector<char> st;
        for(auto x : s){
            if(x == 'A') st.push_back(x);
            else{
                if(st.empty()) st.push_back(x);
                else{
                    st.pop_back();
                }
            }
        }
        cout << st.size() << "\n";

    }
    return 0;
}