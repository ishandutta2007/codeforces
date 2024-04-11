#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n;
int arr[N];
vector < pair < int , int > > ans;
map < int , int > m;
bool ok = 0;
int l = 1;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        ++m[arr[i]];
    }
    for(auto it : m){
        if(it.second > 1){
            ok = 1;
        }
    }
    if(!ok){
        printf("-1\n");
        return 0;
    }
    m.clear();
    for(int i = 1 ; i <= n ; ++i){
        if(m[arr[i]] == 1){
            ans.emplace_back(make_pair(l , i));
            l = i + 1;
            m.clear();
        }
        else{
            ++m[arr[i]];
        }
    }
    if(l != n + 1){
        ans[ans.size() - 1].second = n;   
    }
    printf("%d\n" , int(ans.size()));
    for(auto it : ans){
        printf("%d %d\n" , it.first , it.second);
    }
}