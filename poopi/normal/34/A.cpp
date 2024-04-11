                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define P pair<int, int>

int n;
int len[110];

int main(){
    cin >> n;
    int mn = 10000;
    for(int i = 0; i < n; i++){
        cin >> len[i];
        if(i > 0)
            mn = min(mn, abs(len[i] - len[i-1]));
    }
    if(mn >= abs(len[0] - len[n-1]))
        cout << n << " 1" << endl;
    else{
        for(int i = 0; i < n - 1; i++){
            if(abs(len[i] - len[i+1]) == mn){
                cout << i + 1 << ' ' << i + 2 << endl;
                break;
            }
        }
    }
    return 0;
}