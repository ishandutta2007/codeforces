#include "bits/stdc++.h"
using namespace std;
const int SZ = 3e5 + 5;
struct data{
    int child[26];
    int suf;
    bool leaf;
    int score;
};
data arr[SZ];
int cur;
int que[SZ];
int qs , qe;
struct ahocorasick{
    int root;
    int size;
    void init(){
        root = ++cur;
    }
    void insert(char str[]){
        int node = root;
        for(int i = 0 ; str[i] ; ++i){
            int c = str[i] - 'a';
            if(!arr[node].child[c]){
                arr[node].child[c] = ++cur;
            }
            node = arr[node].child[c];
        }
        ++size;
        arr[node].leaf = 1;
    }
    int find(int node , int c){
        while(node != root){
            if(arr[node].child[c]){
                return arr[node].child[c];
            }
            node = arr[node].suf;
        }
        if(arr[root].child[c]){
            return arr[root].child[c];
        }
        else{
            return root;
        }
    }
    void prepare(){
        qs = 0;
        qe = 0;
        que[qe++] = root;
        arr[root].suf = root;
        while(qs < qe){
            int node = que[qs++];
            for(int i = 0 ; i < 26 ; ++i){
                if(arr[node].child[i]){
                    int next = arr[node].child[i];
                    if(node != root){
                        arr[next].suf = find(arr[node].suf , i);
                    }
                    else{
                        arr[next].suf = root;
                    }
                    arr[next].score = arr[arr[next].suf].score + arr[next].leaf;
                    que[qe++] = next;
                }
            }
        }
    }
    long long query(char str[]){
        int node = root;
        long long res = 0;
        for(int i = 0 ; str[i] ; ++i){
            int c = str[i] - 'a';
            node = find(node , c);
            res += arr[node].score;
        }
        return res;
    }
    void dfs(int mynode , int othernode){
        arr[mynode].leaf |= arr[othernode].leaf;
        for(int i = 0 ; i < 26 ; ++i){
            if(!arr[othernode].child[i]){
                continue;
            }
            if(!arr[mynode].child[i]){
                arr[mynode].child[i] = arr[othernode].child[i];
                continue;
            }
            dfs(arr[mynode].child[i] , arr[othernode].child[i]);
        }
    }
    void merge(ahocorasick other){
        dfs(root , other.root);
        size += other.size;
    }
};
struct onlineahocorasick{
    vector < ahocorasick > v;
    void insert(char str[]){
        ahocorasick tmp;
        tmp.init();
        tmp.insert(str);
        v.emplace_back(tmp);
        while(v.size() > 1 && v[v.size() - 2].size == v[v.size() - 1].size){
            v[v.size() - 2].merge(v[v.size() - 1]);
            v.pop_back();
        }
        v.back().prepare();
    }
    long long query(char str[]){
        long long res = 0;
        for(auto it : v){
            res += it.query(str);
        }
        return res;
    }
};
int n;
int type;
char str[SZ];
onlineahocorasick add , del;
int main(){
    scanf("%d" , &n);
    while(n--){
        scanf("%d %s" , &type , str);
        if(type == 1){
            add.insert(str);
        }
        else if(type == 2){
            del.insert(str);
        }
        else{
            printf("%lld\n" , add.query(str) - del.query(str));
            fflush(stdout);
        }
    }
}