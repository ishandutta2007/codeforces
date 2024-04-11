#include "bits/stdc++.h"
using namespace std;
const int N = 4005;
int n;
int v[N];
int d[N];
long long p[N];
bool done[N];
vector < int > ans;
int main(){
    memset(done , 0 , sizeof(done));
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d %lld" , v + i , d + i , p + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(done[i]){
            continue;
        }
        ans.emplace_back(i);
        int ctr = 0;
        for(int j = i + 1 ; j <= n ; ++j){
            if(!done[j]){
                if(ctr == v[i]){
                    break;
                }
                p[j] -= v[i] - ctr;
                ++ctr;
            }
        }
        long long tot = 0;
        for(int j = i + 1 ; j <= n ; ++j){
            if(!done[j]){
                p[j] -= tot;
                if(p[j] < 0){
                    done[j] = 1;
                    tot += d[j];
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(int x : ans){
        cout << x << " ";
    }
}