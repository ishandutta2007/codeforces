#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

    int n;
    cin >> n;
    ll sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
    }
    sort(sk,sk+n);
    int dis = n;
    ll am = 0;
    for(int i = 0;i<n;i++){
        if(am > sk[i]){
            dis--;
        }
        else{
            am += sk[i];
        }
    }
    cout << dis;
    return 0;
}