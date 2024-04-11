#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N] , b[N];
int q;
int k;
vector < int > arr[N];
int l[N];
int r[N];
vector < int > tmp1;
vector < int > v[N];
int cnt[N];
int disc;
int who[N];
vector < int > indice[N];
bool rekt[N];
int main(){
    scanf("%d" , &n);
    tmp1.clear();
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , a + i , b + i);
        tmp1.emplace_back(a[i]);
        cnt[a[i]] = 1;
    }
    sort(tmp1.begin() , tmp1.end());
    tmp1.resize(unique(tmp1.begin() , tmp1.end()) - tmp1.begin());
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d" , &k);
        arr[i].clear();
        arr[i].resize(k);
        for(int j = 0 ; j < k ; ++j){
            scanf("%d" , &arr[i][j]);
        }
        sort(arr[i].begin() , arr[i].end());
        arr[i].resize(unique(arr[i].begin() , arr[i].end()) - arr[i].begin());
        l[i] = 1;
        r[i] = n;
        int cntc = 0;
        for(int x : arr[i]){
            cntc += cnt[x]; 
        }
        if(cntc == tmp1.size()){
            l[i] = 0;
            r[i] = 0;
        }
    }
    while(1){
        for(int i = 1 ; i <= n ; ++i){
            v[i].clear();
            cnt[i] = 0;
        }
        bool ok = 0;
        for(int i = 1 ; i <= q ; ++i){
            if(l[i] < r[i]){
                int mid = l[i] + r[i] + 1 >> 1;
                v[mid].emplace_back(i);
                ok = 1;
            }
        }
        if(!ok){
            break;
        }
        disc = 0;
        for(int i = n ; i >= 1 ; --i){
            disc += !cnt[a[i]];
            cnt[a[i]] = 1;
            for(int idx : v[i]){
                int val = disc;
                for(int x : arr[idx]){
                    val -= cnt[x];
                }
                if(val >= 1){
                    l[idx] = i;
                }
                else{
                    r[idx] = i - 1;
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        indice[a[i]].emplace_back(i);
    }
    for(int i = 1 ; i <= q ; ++i){
        who[i] = a[l[i]];
        if(who[i] == 0){
            l[i] = 0;
            r[i] = 0;
        }
        else{
            l[i] = 1;
            r[i] = indice[who[i]].size();
        }
    }
    while(1){
        for(int i = 1 ; i <= n ; ++i){
            v[i].clear();
            cnt[i] = 0;
        }
        bool ok = 0;
        for(int i = 1 ; i <= q ; ++i){
            if(l[i] < r[i]){
                int mid = l[i] + r[i] - 2 >> 1;
                v[indice[who[i]][mid]].emplace_back(i);
                ok = 1;
            }
        }
        if(!ok){
            break;
        }
        disc = 0;
        for(int i = n ; i >= 1 ; --i){
            disc += !cnt[a[i]];
            cnt[a[i]] = 1;
            for(int idx : v[i]){
                int val = disc;
                for(int x : arr[idx]){
                    val -= cnt[x];
                }
                if(val > 1){
                    l[idx] = lower_bound(indice[who[idx]].begin() , indice[who[idx]].end() , i + 1) - indice[who[idx]].begin() + 1;
                }
                else{
                    r[idx] = lower_bound(indice[who[idx]].begin() , indice[who[idx]].end() , i + 1) - indice[who[idx]].begin();
                }
            }
        }
    }
    for(int i = 1 ; i <= q ; ++i){
        if(!who[i]){
            puts("0 0");
        }
        else{
            printf("%d %d\n" , who[i] , b[indice[who[i]][l[i] - 1]]);
        }
    }
}