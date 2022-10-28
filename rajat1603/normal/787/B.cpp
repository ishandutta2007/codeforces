#include "bits/stdc++.h"
using namespace std;
int n , m;
int k;
int val;
int main(){
    scanf("%d %d" , &n , &m);
    while(m--){
        scanf("%d" , &k);
        map < int , set < int > > mp;
        mp.clear();
        while(k--){
            scanf("%d" , &val);
            mp[max(val , -val)].insert(val);
        }
        bool ok = 0;
        for(auto it : mp){
            if(it.second.size() == 2){
                ok = 1;
            }
        }
        if(!ok){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}