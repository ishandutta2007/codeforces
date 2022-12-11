#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int n,m;
    cin >> n >> m;
    int pos = m - 1;
    for(int i = 0;i<n;i++){
        if(i % 2 == 0){
            for(int x = 0;x<m;x++){
                cout << "#";
            }
        }
        else{
            for(int x = 0;x<m;x++ ){
                if(x == pos){
                    cout << "#";
                }
                else{
                    cout << ".";
                }
            }
            if(pos == 0){
                pos = m - 1;
            }
            else{
                pos = 0;
            }
        }
        cout << "\n";
    }
	return 0;
}