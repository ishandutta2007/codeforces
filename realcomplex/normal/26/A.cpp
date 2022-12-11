#include <bits/stdc++.h>

using namespace std;

int is(int sk){
    int ans = 0;
    int r = 0;
    for(int i = 2;i<=sqrt(sk);i++){
        r = 0;
        while(sk%i==0){
            sk/=i;
            r++;
        }
        if(r!=0){
            ans++;
        }
    }
    if(sk!=1){
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int an = 0;
    for(int i = 2;i<=n;i++){
        if(is(i) == 2){
            an++;
        }
    }
    cout << an;
    return 0;
}