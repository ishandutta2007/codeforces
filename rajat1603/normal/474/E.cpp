#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const long long MAX = 1e15;
int n , d;
long long h[N];
int nxt[N];
int print;
struct node{
    pair < int , int > val;
    node* left;
    node* right;
    node(pair < int , int > _val = make_pair(0 , n + 1) , node* _left = NULL , node* _right = NULL){
        val = _val;
        left = _left;
        right = _right;
    }
};
typedef node* pnode;
pair < int , int > val(pnode tree){
    if(tree){
        return tree -> val;
    }
    return make_pair(0 , n + 1);
}
void update(long long l , long long r , pnode &tree , long long idx , int value , int pos){
    if(!tree){
        tree = new node();
    }
    if(l == r){
        tree -> val = max(tree -> val , make_pair(value , pos));
        return;
    }
    long long mid = l + r >> 1;
    if(idx <= mid){
        update(l , mid , tree -> left , idx , value , pos);
    }
    else{
        update(mid + 1 , r , tree -> right , idx , value , pos);
    }
    tree -> val = max(val(tree -> left) , val(tree -> right));
}
pair < int , int > query(long long l , long long r , pnode tree , long long ql , long long qr){
    if(!tree || l > qr || r < ql || ql > qr){
        return make_pair(0 , n + 1);
    }
    if(l >= ql && r <= qr){
        return val(tree);
    }
    long long mid = l + r >> 1;
    return max(query(l , mid , tree -> left , ql , qr) , query(mid + 1 , r , tree -> right , ql , qr));
}
pnode root = NULL;
int main(){
    scanf("%d %d" , &n , &d);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld" , h + i);
        nxt[i] = n + 1;
    }
    for(int i = n ; i >= 1 ; --i){
        auto it = max(query(1 , MAX , root , h[i] + d , MAX) , query(1 , MAX , root , 1 , h[i] - d));
        nxt[i] = it.second;
        update(1 , MAX , root , h[i] , it.first + 1 , i);
    }
    printf("%d\n" , val(root).first);
    print = val(root).second;
    while(print <= n){
        printf("%d " , print);
        print = nxt[print];
    }
}