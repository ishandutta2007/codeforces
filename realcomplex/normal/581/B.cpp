#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second

int main()
{
    int n;
    cin >> n;
    int h[n];
    for(int i = 0;i<n;i++){
        cin >> h[i];
    }
    int add[n];
    add[n-1] = 0;
    int mx = h[n-1];
    for(int i = n-2;i>=0;i--){
        if(h[i] > mx){
            add[i] = 0;
            mx = h[i];
        }
        else{
            add[i] = abs(mx-h[i])+1;
        }
    }
    for(int x = 0;x<n;x++){
        cout << add[x] << " ";
    }
    return 0;
}