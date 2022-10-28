#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
int a , b;
int c , d;
int e , f;
char ans[N][N];
void print(int n){
    printf("%d\n" , n);
    for(int i = 1 ; i < N ; ++i){
        printf("%s\n" , ans[i] + 1);
    }
    exit(0);
}
void lol(int a , int b , int c , int d , int e , int f , char s1 , char s2 , char s3){
    if(b == d && d == f && (b == (a + e + c))){
        for(int i = 1 ; i <= a ; ++i){
            for(int j = 1 ; j <= b ; ++j){
                ans[j][i] = s1;
            }
        }
        for(int i = a + 1 ; i <= a + c ; ++i){
            for(int j = 1 ; j <= d ; ++j){
                ans[j][i] = s2;
            }
        }
        for(int i = a + c + 1 ; i <= a + c + e ; ++i){
            for(int j = 1 ; j <= f ; ++j){
                ans[j][i] = s3;
            }
        }
        print(b);
    }
    if(a == c && c == e && (a == (b + d + e))){
        for(int i = 1 ; i <= a ; ++i){
            for(int j = 1 ; j <= b ; ++j){
                ans[j][i] = s1;
            }
        }
        for(int i = 1 ; i <= a ; ++i){
            for(int j = b + 1 ; j <= b + d ; ++j){
                ans[j][i] = s2;
            }
        }
        for(int i = 1 ; i <= a; ++i){
            for(int j = b + d + 1 ; j <= b + d + f ; ++j){
                ans[j][i] = s3;
            }
        }
        print(a);
    }
    if(a == c && b + d == f && (a + e == f)){
        for(int i = 1 ; i <= a ; ++i){
            for(int j = 1 ; j <= b ; ++j){
                ans[j][i] = s1;
            }
        }
        for(int i = 1 ; i <= a ; ++i){
            for(int j = b + 1 ; j <= b + d ; ++j){
                ans[j][i] = s2;
            }
        }
        for(int i = a + 1 ; i <= a + e ; ++i){
            for(int j = 1 ; j <= f ; ++j){
                ans[j][i] = s3;
            }
        }
        print(a + e);
    }
    if(b == d && a + c == e && (a + c == f + b)){
        for(int i = 1 ; i <= a ; ++i){
            for(int j = 1 ; j <= b ; ++j){
                ans[j][i] = s1;
            }
        }
        for(int i = a + 1 ; i <= a + c ; ++i){
            for(int j = 1 ; j <= b ; ++j){
                ans[j][i] = s2;
            }
        }
        for(int i = 1 ; i <= e ; ++i){
            for(int j = b + 1 ; j <= b + f ; ++j){
                ans[j][i] = s3;
            }
        }
        print(e);
    }
}
void solve(int a , int b , int c , int d , int e , int f){
    lol(a , b , c , d , e , f , 'A' , 'B' , 'C');
    lol(a , b , e , f , c , d , 'A' , 'C' , 'B');
    lol(c , d , a , b , e , f , 'B' , 'A' , 'C');
    lol(c , d , e , f , a , b , 'B' , 'C' , 'A');
    lol(e , f , a , b , c , d , 'C' , 'A' , 'B');
    lol(e , f , c , d , a , b , 'C' , 'B' , 'A');
}
int main(){
    cin >> a >> b >> c >> d >> e >> f;
    solve(a , b , c , d , e , f);
    solve(b , a , c , d , e , f);
    solve(a , b , d , c , e , f);
    solve(b , a , d , c , e , f);
    solve(a , b , c , d , f , e);
    solve(b , a , c , d , f , e);
    solve(a , b , d , c , f , e);
    solve(b , a , d , c , f , e);
    cout << "-1";
}