#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-8;
int n , m , k , input;
bool ban[N] = {0};
vector < int > v[N];
int degree[N] = {0};
double ans = -0.1;
set < pair < double , int > > pq;
bool visited[N] = {0};
vector < int > kicked;
int indice;
int main(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= k ; ++i){
        cin >> input;
        ban[input] = 1;
    }
    for(int i = 1 ; i <= m ; ++i){
        cin >> k >> input;
        v[input].emplace_back(k);
        v[k].emplace_back(input);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!ban[i]){
            for(int next : v[i]){
                degree[next]++;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!ban[i]){
            pq.insert(make_pair(1.0 * degree[i] / v[i].size() , i));
        }
    }
    while(!pq.empty()){
        int node = pq.begin() -> second;
        if(pq.begin() -> first + eps >= ans){
            ans = pq.begin() -> first;
            indice = kicked.size();
        }
        visited[node] = 1;
        pq.erase(pq.begin());
        kicked.emplace_back(node);
        for(int next : v[node]){
            if(!visited[next] && !ban[next]){
                pq.erase(make_pair(1.0 * degree[next] / v[next].size() , next));
                degree[next]--;
                pq.insert(make_pair(1.0 * degree[next] / v[next].size() , next));
            }
        }
    }
    cout << kicked.size() - indice << "\n";
    for(int i = indice ; i < kicked.size() ; ++i){
        cout << kicked[i] << " ";
    }
}