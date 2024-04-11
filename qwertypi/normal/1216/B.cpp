#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
vector<pair<int,int>> A;
 
int cmp(pair<int, int> A, pair<int, int> B){
    return A.first > B.first;
}
 
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int v;
        cin >> v;
        pair<int, int> p{v, i};
        A.push_back(p);
    }
    sort(A.begin(), A.end(), cmp);
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += i * A[i].first + 1;
    }
    cout << ans << endl;
    for(int i=0;i<n;i++){
        cout << A[i].second + 1 << ' ';
    }
}