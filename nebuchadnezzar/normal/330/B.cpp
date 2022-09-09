#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, a, b;
bool mas[1000];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        --a;
        --b;
        mas[a] = true;
        mas[b] = true;

    }
//    bool truly = false;
    for(int i = 0; i < n; ++i){
        if(not mas[i]){
            cout << n - 1 << endl;
            for(int j = 0; j < n; ++j){
                if(j != i){
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
            return 0;
        }
    }

    cout << 2 * n - 2 << endl;
    for(int i = 0; i < n; ++i){
        if(i != a && i != b){
            cout << a + 1 << " " << i + 1 << endl;
        }
    }
    for(int i = 0; i < n; ++i){
        if(i != a && i != b){
            cout << b + 1 << " " << i + 1 << endl;
        }
    }
       
    return 0;
}