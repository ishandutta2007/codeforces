#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define mp make_pair

int main()
{
    int n;
    cin >> n;
    int sk,l;
    cin >> l;
    int c = 1,mx = 0;
    for(int i = 1;i<n;i++){
        cin >> sk;
        if(sk>l){
            c++;
        }
        else{
            c = 1;
        }
        if(c > mx){
            mx = c;
        }
        l = sk;
    }
    if(c > mx){
        mx = c;
    }
    cout << mx;
    return 0;
}