#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define f first
#define s second

int main(){

    int n;
    cin >> n;
    int mn = (1e9)*2;
    int sk[n];
    for(int i = 0;i<n;i++){
        cin >> sk[i];
        mn = min(mn,sk[i]);
    }
    for(int x = 0;x<n;x++){
        if(sk[x]%mn!=0){
            mn = -1;
            break;
        }
    }
    cout << mn;
    return 0;
}