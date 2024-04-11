#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second
#define t abs

int main(){

    int n;
    cin >> n;
    int s[n];
    int k[n];
    char r;
    for(int i = 0;i<n;i++){
        cin >> r;
        s[i] = r-48;
    }
    for(int x = 0;x<n;x++){
        cin >> r;
        k[x] = r-48;
    }
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += min(min(abs(s[i]-k[i]),(10-s[i])+k[i]),(10-k[i])+s[i]);
    }
    cout << sum;
    return 0;
}