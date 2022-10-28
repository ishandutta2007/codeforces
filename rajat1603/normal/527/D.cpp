#include "bits/stdc++.h"
using namespace std;
struct treap{
    struct node{
        int idx;
        int val;
        int maxx;
        int pri;
        node* left;
        node* right;
        node(int _pos = -1 , int _val = -1){
            idx = _pos;
            val = _val;
            maxx = _val;
            pri = rand();
            left = NULL;
            right = NULL;
        }
    };
    typedef node* pnode;
    pnode root;
    treap(){
        root = NULL;
        srand(time(NULL));
    }
    int maxx(pnode tree){
        if(tree){
            return tree -> maxx;
        }
        return 0;
    }
    void upd(pnode &tree){
        if(tree){
            tree -> maxx = max(max(maxx(tree -> left) , maxx(tree -> right)) , tree -> val);
        }
    }
    void split(pnode tree , pnode &l , pnode &r , int key){
        if(!tree){
            l = NULL;
            r = NULL;
        }
        else if(tree -> idx <= key){
            split(tree -> right , tree -> right , r , key);
            l = tree;
        }
        else{
            split(tree -> left , l , tree -> left , key);
            r = tree;
        }
        upd(tree);
    }
    void merge(pnode &tree , pnode l , pnode r){
        if(!l || !r){
            tree = l ? l : r;
        }
        else if(l -> pri > r -> pri){
            merge(l -> right , l -> right , r);
            tree = l;
        }
        else{
            merge(r -> left , l , r -> left);
            tree = r;
        }
        upd(tree);
    }
    void insert(pnode &tree , pnode key){
        if(!tree){
            tree = key;
        }
        else if(key -> pri > tree -> pri){
            split(tree , key -> left , key -> right , key -> idx);
            tree = key;
        }
        else if(tree -> idx >= key -> idx){
            insert(tree -> left , key);
        }
        else{
            insert(tree -> right , key);
        }
        upd(tree);
    }
    void insert(int idx , int value){
        insert(root , new node(idx , value));
    }
    int query(pnode tree , int idx){
        if(!tree){
            return 0;
        }
        else if(tree -> idx <= idx){
            return max(max(maxx(tree -> left) , tree -> val) , query(tree -> right , idx));
        }
        else{
            return query(tree -> left , idx);
        }
    }
    int query(int idx){
        return query(root , idx);
    }
};
const int N = 2e5 + 5;
pair < int  , int > arr[N];
int n;
int ans = 0;
treap rdtree;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second);
    }
    sort(arr + 1 , arr + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        int temp = rdtree.query(arr[i].first - arr[i].second) + 1;
        ans = max(ans , temp);
        rdtree.insert(arr[i].first + arr[i].second , temp);
    }
    printf("%d\n" , ans);
}