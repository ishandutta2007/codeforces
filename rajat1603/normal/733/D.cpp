#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N] , b[N] , c[N];
int idx1;
int ans1;
int idxa , idxb;
int ans2;
map < pair < int , int > , pair < int , int > > mp;
int mult(int x , int y){
    return min(x , y);
}
void check(pair < int , int > x ,  int z , int i){
    if(mp.find(x) != mp.end()){
        auto it = mp[x];
        double tmp = mult(mult(x.first , x.second) , it.first + z);
        if(ans2 < tmp){
            ans2 = tmp;
            idxa = it.second;
            idxb = i;
        }
    }
}
void insert(pair < int , int > x , int z , int i){
    mp[x] = max(mp[x] , make_pair(z , i));
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d %d" , a + i , b + i , c + i);
    }
    mp.clear();
    for(int i = 1 ; i <= n ; ++i){
        double tmp = mult(a[i] , mult(b[i] , c[i]));
        if(ans1 < tmp){
            ans1 = tmp;
            idx1 = i;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        check(make_pair(a[i] , b[i]) , c[i] , i);
        check(make_pair(b[i] , c[i]) , a[i] , i);
        check(make_pair(c[i] , a[i]) , b[i] , i);
        check(make_pair(b[i] , a[i]) , c[i] , i);
        check(make_pair(c[i] , b[i]) , a[i] , i);
        check(make_pair(a[i] , c[i]) , b[i] , i);
        insert(make_pair(a[i] , b[i]) , c[i] , i);
        insert(make_pair(b[i] , c[i]) , a[i] , i);
        insert(make_pair(c[i] , a[i]) , b[i] , i);
        insert(make_pair(b[i] , a[i]) , c[i] , i);
        insert(make_pair(c[i] , b[i]) , a[i] , i);
        insert(make_pair(a[i] , c[i]) , b[i] , i);
    }
    if(ans2 < ans1){
        printf("1\n%d\n" , idx1);
    }
    else{
        printf("2\n%d %d\n" , idxa , idxb);
    }
}