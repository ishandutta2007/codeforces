#include "bits/stdc++.h"
using namespace std;
const int N = 200001;
struct query{
    int id;
    int l;
    int r;
    int val;
    query(int _id , int _l , int _r , int _val){
        id = _id;
        l = _l;
        r = _r;
        val = _val;
    }
    bool operator < (const query &b) const{
        return val < b.val;
    }
};
int n;
int ans[N] = {0};
vector<query> v;
int bit[N] = {0};
pair < int , int > arr[N];
int sum(int idx){
    int res = 0;
    while(idx){
        res += bit[idx];
        idx &= idx - 1;
    }
    return res;
}
int add(int idx){
    while(idx <= n){
        ++ bit[idx];
        idx += idx&-idx;
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d",&arr[i].first);
        arr[i].second = i;
    }
    for(int k = 1 ; k < n ; ++k){
        for(int i = 1 ; ; ++i){
            int leftchild = k * (i - 1) + 2;
            int rightchild = min(k * i + 1 , n);
            if(leftchild > n){
                break;
            }
            v.push_back(query(k , leftchild , rightchild , arr[i].first));
        }
    }
    sort(v.begin() , v.end());
    sort(arr + 1 , arr + 1 + n);
    int cur = 1;
    for(vector<query>::iterator it = v.begin() ; it != v.end() ; ++it){
        while(it -> val > arr[cur].first){
            add(arr[cur++].second);
        }
        ans[it -> id] += sum(it -> r) - sum(it -> l - 1);
    }
    for(int i = 1 ; i < n ; ++i){
        printf("%d ",ans[i]);
    }
}