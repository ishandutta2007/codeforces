#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 100005;
struct trie{
    //FIRST TIME WRITING A TRIE 
    int size;
    trie *left;
    trie *right;
    trie(){
        size = 0;
        left = NULL;
        right = NULL;
    }
    trie *insert(long long val,int level){
        ++size;
        if(level<0){
            return this;
        }
        if((val>>level)&1LL){
            if(right==NULL){
                right = new trie();
            }
            right = right->insert(val,level-1);
        }
        else{
            if(left==NULL){
                left = new trie();
            }
            left = left->insert(val,level-1);
        }
        return this;
    }
    long long query(long long value,int level){
        if(level<0){
            return 0;
        }
        if((value>>level)&1LL){
            if(left==NULL){
                return right->query(value,level-1);
            }
            else{
                return (1LL<<level)|left->query(value,level-1);
            }
        }
        else{
            if(right==NULL){
                return left->query(value,level-1);
            }
            else{
                return (1LL<<level)|right->query(value,level-1);
            }
        }
    }
};
trie *root = new trie();
long long arr[N];
int n;
const int LN = 40;
int main(){
    scanf("%d",&n);
    long long prefix = 0;
    for(int i = 1; i <= n ; ++i){
        scanf("%lld",&arr[i]);
        prefix^=arr[i];
    }
    long long suffix = 0;
    long long ans = 0;
    root = root->insert(0,LN);
    for(int i = 1; i <= n ; ++i){
        ans = max ( ans , root->query(prefix,LN));
        suffix^=arr[i];
        prefix^=arr[i];
        root = root->insert(suffix,LN);
    }
    ans = max(ans , root->query(0,LN));
    printf("%lld",ans);
}