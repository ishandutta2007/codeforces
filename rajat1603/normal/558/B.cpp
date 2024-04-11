#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 20;
int freq[N];
int lft[N];
int rgt[N];
int n , inp;
int num = 0;
int main(){
    memset(freq , 0 , sizeof(freq));
    memset(lft , -1 , sizeof(lft));
    memset(rgt , -1 , sizeof(rgt));
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> inp;
        if(lft[inp] == -1){
            lft[inp] = i;
        }
        rgt[inp] = i;
        freq[inp]++;

    }
    for(int i = 0 ; i < N ; ++i){
        if(freq[i] > freq[num]){
            num = i;
        }
        else if(freq[i] == freq[num]){
            if(rgt[i] - lft[i] < rgt[num] - lft[num]){
                num = i;
            }
        }
    }
    cout << lft[num] << " " << rgt[num];
}