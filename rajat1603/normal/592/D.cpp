#include "bits/stdc++.h"
using namespace std;
const int N = 123456 + 5;
int n , k;
vector < int > v[N];
int subtree[N];
bool attacked[N];
int cnt[N];
int a , b;
int baap = -1;
int root = -1;
int dist[N];
int name[N];
int ans;
int mxdist;
void dfs(int node , int parent){
    subtree[node] = 1;
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
            subtree[node] += subtree[next];
            cnt[node] += cnt[next];
        }
    }
    if(cnt[node] == k && root == -1){
        root = node;
        baap = parent;
    }
}
int count(int node , int parent){
    if(!cnt[node]){
        return 0;
    }
    int ret = 1;
    for(int next : v[node]){
        if(next != parent){
            ret += count(next , node);
        }
    }
    return ret;
}
int answer1 = N;
void dfs2(int node , int parent){
    dist[node] = -N;
    if(!cnt[node]){
        return;
    }
    if(attacked[node]){
        dist[node] = 0;
        name[node] = node;
    }
    int mx = 0;
    int mx2 = -2;
    int name1 = N;
    int name2 = N;
    for(int next : v[node]){
        if(next != parent){
            dfs2(next , node);
            if(dist[next] + 1 > dist[node]){
                dist[node] = dist[next] + 1;
                name[node] = name[next];
            }
            else if(dist[next] + 1 == dist[node]){
                name[node] = min(name[node] , name[next]);
            }
            //Chutiyapa for lexicographically smallest start
            if(dist[next] + 1 > mx){
                mx2 = mx;
                name2 = name1;
                mx = dist[next] + 1;
                name1 = name[next];
            }
            else if(dist[next] + 1 == mx){
                if(mx == mx2){
                    if(name[next] < name2){
                        if(name[next] < name1){
                            name2 = name1;
                            name1 = name[next];
                        }
                        else if(name[next] < name2){
                            name2 = name[next];
                        }
                    }
                }
                else{
                    name2 = name[next];
                    mx2 = dist[next] + 1;
                }
            }
            else if(dist[next] + 1 > mx2){
                mx2 = dist[next] + 1;
                name2 = name[next];
            }
            else if(dist[next] + 1 == mx2){
                name2 = min(name2 , name[next]);
                if(mx == mx2){
                    if(name1 > name2){
                        swap(name1 , name2);
                    }
                }
            }
            //Chutiyapa for lexicographically smallest finish
        }
    }
    if(mx + mx2 > mxdist){
        mxdist = mx + mx2;
        answer1 = min(name1 , name2);//Chutiyapa for lexicographically smallest
    }
    else if(mx + mx2 == mxdist){//Chutiyapa for lexicographically smallest
        answer1 = min(answer1 , min(name1 , name2));//Chutiyapa for lexicographically smallest
    }//Chutiyapa for lexicographically smallest
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d" , &a);
        cnt[a] = 1;
        attacked[a] = 1;
    }
    dfs(1 , -1);
    int ans = (count(root , baap) - 1) << 1;
    dfs2(root , baap);
    if(dist[root] > mxdist){
        mxdist = dist[root];
        answer1 = root;
    }
    else if(dist[root] == mxdist){//Chutiyapa for lexicographically smallest
        answer1 = min(answer1 , root);//Chutiyapa for lexicographically smallest
    }//Chutiyapa for lexicographically smallest
    ans -= mxdist;
    printf("%d %d\n" , answer1 , ans);
}