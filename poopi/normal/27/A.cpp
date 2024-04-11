                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define P pair<int, int>

int n, t;
bool mark[3010];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        mark[t] = true;
    }
    int p = 1;
    while(mark[p])
        p++;
    cout << p << endl;
    return 0;
}