#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n , m;
int a , b;
pair < int , int > edges[N];
int s , t;
int d[N];
int parent[N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
vector < pair < int , int > > ans;
int comp[N];
int cur;
int aedge[N];
int bedge[N];
int who[N];
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
        d[i] = n + 1;
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        if(a > b){
            swap(a , b);
        }
        edges[i] = make_pair(a , b);
    }
    scanf("%d %d" , &s , &t);
    scanf("%d %d" , &d[s] , &d[t]);
    if(s > t){
        swap(s , t);
    }
    ans.clear();
    for(int i = 1 ; i <= m ; ++i){
        a = edges[i].first;
        b = edges[i].second;
        if(a == s || a == t || b == s || b == t){
            continue;
        }
        if(find(a) != find(b)){
            parent[find(a)] = find(b);
            ans.emplace_back(make_pair(a , b));
        }
    }
    cur = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(i == s || i == t){
            continue;
        }
        if(find(i) == i){
            ++cur;
            comp[i] = cur;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(i == s || i == t){
            continue;
        }
        comp[i] = comp[find(i)];
    }
    for(int i = 1 ; i <= cur ; ++i){
        aedge[i] = 0;
        bedge[i] = 0;
        who[i] = 0;
    }
    for(int i = 1 ; i <= m ; ++i){
        int a = edges[i].first;
        int b = edges[i].second;
        if(a == s && b == t){
            continue;
        }
        if(a == s || b == s){
            aedge[comp[a ^ b ^ s]] = a ^ b ^ s;
        }
        if(a == t || b == t){
            bedge[comp[a ^ b ^ t]] = a ^ b ^ t;
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        if(!aedge[i]){
            if(bedge[i]){
                ans.emplace_back(make_pair(t , bedge[i]));
                --d[t];
                who[i] = 2;
            }
        }
        if(!bedge[i]){
            if(aedge[i]){
                ans.emplace_back(make_pair(s , aedge[i]));
                --d[s];
                who[i] = 1;
            }
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        if(aedge[i] && bedge[i]){
            if(d[s] > d[t]){
                ans.emplace_back(make_pair(s , aedge[i]));
                --d[s];
                who[i] = 1;
            }
            else{
                ans.emplace_back(make_pair(t , bedge[i]));
                --d[t];
                who[i] = 2;
            }
        }
    }
    bool done = 0;
    for(int i = 1 ; i <= cur ; ++i){
        if(aedge[i] && bedge[i]){
            if(who[i] == 1 && d[t] > 0){
                --d[t];
                ans.emplace_back(make_pair(t , bedge[i]));
                done = 1;
                break;
            }
            if(who[i] == 2 && d[s] > 0){
                --d[s];
                ans.emplace_back(make_pair(s , aedge[i]));
                done = 1;
                break;
            }
        }
    }
    if(!done){
        for(int i = 1 ; i <= m ; ++i){
            if(edges[i].first == s && edges[i].second == t){
                ans.emplace_back(make_pair(s , t));
                --d[s];
                --d[t];
            }
        }
    }
    if(d[s] >= 0 && d[t] >= 0 && ans.size() == n - 1){
        printf("Yes\n");
        for(auto it : ans){
            printf("%d %d\n" , it.first , it.second);
        }
    }
    else{
        printf("No\n");
    }
}