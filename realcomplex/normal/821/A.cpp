#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;
    int sk[n][n];
    for(int i = 0;i<n;i++){
        for(int x = 0;x<n;x++){
            cin >> sk[i][x];
        }
    }
    bool c = true;
    bool cu;
    for(int i = 0;i<n;i++){
        for(int x = 0;x<n;x++){
            if(sk[i][x] != 1){
                cu = false;
                for(int y = 0;y<n;y++){
                    for(int e = 0;e<n;e++){
                        if(sk[i][y] + sk[e][x] == sk[i][x]){
                            cu = true;
                        }
                    }
                }
                if(cu == false){
                    c = cu;
                }
            }
        }
    }
    if(c == false){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
	return 0;
}