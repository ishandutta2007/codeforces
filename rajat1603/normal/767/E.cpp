#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int c[N];
int w[N];
int ans[N];
priority_queue < pair < int , int > > pq;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , c + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , w + i);
    }
    while(!pq.empty()){
        pq.pop();
    }
    for(int i = 1 ; i <= n ; ++i){
        ans[i] = 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        int val = c[i] % 100;
        if(val){
            if(m >= val){
                ans[i] = val;
                m -= val;
                pq.push(make_pair(-(w[i] * (100 - val)) , i));
                //cout << i << " " << "Nice\n";
            }
            else{
                if(!pq.empty()){
                    auto it = pq.top();
                    if(-it.first > (100 - val) * w[i]){
                        m += 100 - val;
                        ans[i] = 0;
                        //cout << i << " " << "Rekt1\n";
                    }
                    else{
                        //cout << i << " " << "Not rekt\n" << " " << it.second << endl;
                        pq.pop();
                        m += 100;
                        ans[i] = val;
                        m -= val;
                        ans[it.second] = 0; 
                        pq.push(make_pair(-(w[i] * (100 - val)) , i));
                    }
                }
                else{
                    //cout << i << " " << "Rekt2\n";
                    m += 100 - val;
                    ans[i] = 0;
                }
            }
        }
        else{
            ans[i] = 0;
        }
    }
    long long print = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(c[i] % 100){
            if(ans[i] == 0){
                print += (100 - (c[i] % 100)) * w[i];
            }
        }
    }
    printf("%lld\n" , print);
    for(int i = 1 ; i <= n ; ++i){
        if(c[i] % 100){
            if(ans[i]){
                printf("%d %d\n" , c[i] / 100 , ans[i]);
            }
            else{
                printf("%d %d\n" , (c[i] / 100) + 1 , 0);
            }
        }
        else{
            printf("%d %d\n" , c[i] / 100 , 0);
        }
    }
}