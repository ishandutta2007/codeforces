#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
float timer = 1.4099999;
set < pair < int , int > > s;
int n , m;
vector < int > v;
int degree[N];
int main(){
    int start = clock();
    cin >> n >> m;
    for(int i = 1 ; i <= m ; ++i){
        cin >> degree[0] >> degree[1];
        sort(degree , degree + 2);
        s.insert(make_pair(degree[0] , degree[1]));
    }
    for(int i = 1 ; i <= n ; ++i){
        v.emplace_back(i);
    }
    while(((1.0 * clock() - start) / (1.0 * CLOCKS_PER_SEC)) < timer){
        random_shuffle(v.begin() , v.end());
        bool b = 0;
        set < pair < int , int > > edges;
        memset(degree , 0 , sizeof(int) * N);
        for(int i = 0 ; i < m ; ++i){
            int temp[2];
            temp[0] = v[i % n];
            temp[1] = v[(i + 1) % n];
            sort(temp , temp + 2);
            if(s.find(make_pair(temp[0] , temp[1])) != s.end()){
                b = 1;
                break;
            }
            for(int j = 0 ; j < 2 ; ++j){
                degree[temp[j]]++;
                if(degree[temp[j]] > 2){
                    b = 1;
                    i = m + 1;
                    break;
                }
            }
            edges.insert(make_pair(temp[0] , temp[1]));
        }
        if(edges.size() != m){
            b = 1;
        }
        if(!b){
            for(auto it : edges){
                cout << it.first << " " << it.second << "\n";
            }
            return 0;
        }
    }
    cout << -1;
}