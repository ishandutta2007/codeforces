#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool be = false;
int n,m;
char cur;

int main(){
    cin >> n >> m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> cur;
            if(cur == 'C' || cur == 'M' || cur == 'Y') be = true;
        }

    }
    if(be) cout << "#Color" << endl;
    else cout << "#Black&White" << endl;
    return 0;
}