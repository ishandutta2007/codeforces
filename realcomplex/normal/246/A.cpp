#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main()
{   
    int n;
    cin >> n;
    if(n <= 2){
        cout << -1;
    }
    else{
        for(int i = n;i>0;i--){
            cout << i << " ";
        }
    }
    return 0;
}