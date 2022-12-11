#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    int t,t1;
    cin >> t >> t1;
    int sk[n];
    int v[m];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    for(int j = 0;j<m;j++){
        cin >> v[j];
    }
    t--;
    t1 = m-t1;
    if(sk[t] < v[t1]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}