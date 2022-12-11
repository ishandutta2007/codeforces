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
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> uni;
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
            uni.insert(a[i]);
        }
        if(uni.size() == 2){
            cout << n/2 + 1 << "\n";
        }
        else{
            cout << n << "\n";
        }

    }
    return 0;
}