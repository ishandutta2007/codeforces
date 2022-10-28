#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 200001;
const int M = 500001;
int n , q;
int arr[N];
int cnt[M] = {0};
list<int> primefactors[M];
long long ans = 0;
int cur = 0;
bool present[N] = {0};
void pre(){
    for(int i = 2 ; i < M ; ++i){
        if(!primefactors[i].size()){
            for(int j = i ; j < M ; j += i){
                primefactors[j].pb(i);
            }
        }
    }
}
bool update(int num , int val){
    int x = primefactors[num].size();
    int p = 1 << x;
    for(int i = 1 ; i < p ; ++i){
        int temp = 1;
        list<int>::iterator it = primefactors[num].begin();
        for(int j = 0 ; j < x ; ++j){
            if(i & (1 << j)){
                temp *= *it;
            }
            ++ it;
        }
        cnt[temp] += val;
    }
    cur += val;
    return 0;
}
int calc(int num){
    int res = 0;
    int x = primefactors[num].size();
    int p = 1 << x;
    for(int i = 1 ; i < p ; ++i){
        int temp = 1;
        bool sz = 0;
        list<int>::iterator element = primefactors[num].begin();
        for(int j = 0 ; j < x ; ++j){
            if(i & (1 << j)){
                temp *= *element;
                sz ^= 1;
            }
            ++ element ;
        }
        res += cnt[temp] * ( sz? 1 : -1 );
    }
    return res;
}
int main(){
    cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    pre();
    while(q--){
        int idx;
        cin >> idx;
        int num = arr[idx];
        present[idx] ^= 1;
        ans += present[idx]? cur - calc(num) : update(num , -1);
        ans -= present[idx]? update(num , 1) : cur - calc(num) ;
        cout << ans << "\n";
    }
}