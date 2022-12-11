#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int main(){

    int n;
    cin >> n;
    int z,o;
    z = 0;
    o = 0;
    char s;
    for(int y = 0;y<n;y++){
        cin >> s;
        if(s == '0'){
            z++;
        }
        else{
            o++;
        }
    }
    cout << n-(min(z,o)*2);
    return 0;
}