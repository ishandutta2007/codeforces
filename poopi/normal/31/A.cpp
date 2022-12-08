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
    for(int i = 0; i < n; i++)
        cin >> len[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            for(int k = 0; k < n; k++){
                if(k == i || k == j) continue;
                if(len[i] == len[j] + len[k]){
                    cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}