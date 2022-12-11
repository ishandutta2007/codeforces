#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n,m;
    cin >> n >> m;
    int j = 1;
    while(n>0){
        n--;
        if(j%m==0){
            n++;
        }
        j++;
    }
    cout << j-1;
    return 0;
}