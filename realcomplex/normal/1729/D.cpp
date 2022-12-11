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
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<int> x(n);
        vector<int> y(n);
        for(int i = 0 ; i < n; i ++ ) cin >> x[i];
        for(int i = 0 ; i < n; i ++ ) cin >> y[i];
        vector<int> w;
        for(int i = 0 ; i < n; i ++ ){
            w.push_back(y[i] - x[i]);
        }
        sort(w.begin(), w.end());
        reverse(w.begin(), w.end());
        multiset<int> single;
        int gr = 0;
        for(int i = 0 ; i < n; i ++ ){
            if(w[i] >= 0){
                single.insert(w[i]);
            }
            else{
                auto it = single.lower_bound(-w[i]);
                if(it != single.end()){
                    single.erase(it);
                    gr ++ ;
                }
            }
        }
        cout << gr + (int)single.size() / 2 << "\n";
    }
    return 0;
}