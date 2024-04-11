#include "bits/stdc++.h"
using namespace std;
const int N = 205;
int t;
int n , m;
int a , b;
set < int > s[N];
int deg[N];
vector < pair < int , int > > ans;
vector < pair < int , int > > edges;
int answer;
int main(){
    scanf("%d" , &t);
    while(t--){
        scanf("%d %d" , &n , &m);
        for(int i = 1 ; i <= n ; ++i){
            s[i].clear();
            deg[i] = 0;
        }
        ans.clear();
        edges.clear();
        edges.resize(m);
        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d" , &a , &b);
            s[a].insert(b);
            s[b].insert(a);
            edges[i] = make_pair(a , b);
        }
        for(int i = 0 ; i < m ; ++i){
            a = edges[i].first;
            b = edges[i].second;
            if(s[a].find(b) == s[a].end()){
                continue;
            }
            s[a].erase(b);
            s[b].erase(a);
            ans.emplace_back(make_pair(a , b));
            --deg[a];
            ++deg[b];
            while(!(s[a].empty() && s[b].empty())){
                if(!s[a].empty()){
                    int x = *s[a].begin();
                    s[a].erase(x);
                    s[x].erase(a);
                    ++deg[a];
                    --deg[x];
                    ans.emplace_back(make_pair(x , a));
                    a = x;
                    if(a == b){
                        break;
                    }
                }
                if(!s[b].empty()){
                    int x = *s[b].begin();
                    s[b].erase(x);
                    s[x].erase(b);
                    --deg[b];
                    ++deg[x];
                    ans.emplace_back(make_pair(b , x));
                    b = x;
                    if(a == b){
                        break;
                    }
                }
            }
        }
        answer = 0;
        for(int i = 1 ; i <= n ; ++i){
            answer += !deg[i];
        }
        printf("%d\n" , answer);
        for(auto it : ans){
            printf("%d %d\n" , it.first , it.second);
        }
    }
}