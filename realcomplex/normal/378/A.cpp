#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int a,b;
    cin >> a >> b;
    int fi,se,th;
    fi = 0;
    se = 0;
    th = 0;
    for(int j = 1;j<=6;j++){
        if(abs(j-a) == abs(j-b)){
            se++;
        }
        else if(abs(j-a) < abs(j-b)){
            fi++;
        }
        else{
            th++;
        }
    }
    cout << fi << " " << se << " " << th;
    return 0;
}