#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second

int main(){

    ios_base::sync_with_stdio(false);cin.tie();
    int n;
    cin >> n;
    int sk[n*2];
    for(int i = 0;i<n*2;i++){
        cin >> sk[i];
    }
    sort(sk,sk+(n*2));
    if(sk[n] > sk[n-1]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}