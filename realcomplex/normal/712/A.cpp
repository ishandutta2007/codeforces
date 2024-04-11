#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int sk[n];
    for(int j = 0;j<n;j++){
        cin >> sk[j];
    }
    for(int i = 0;i<n-1;i++){
        cout << sk[i]+sk[i+1] << " ";
    }
    cout << sk[n-1];
    return 0;
}