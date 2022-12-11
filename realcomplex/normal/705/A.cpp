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
    for(int i = 0;i<n-1;i++){
        if(i%2 == 0){
            cout << "I hate that ";
        }
        else{
            cout << "I love that ";
        }
    }
    if(n%2 == 1){
        cout << "I hate it";
    }
    else{
        cout << "I love it";
    }
    return 0;
}