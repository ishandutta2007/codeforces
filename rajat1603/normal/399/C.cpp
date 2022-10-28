#include "bits/stdc++.h"
using namespace std;
int a , b;
long long ans = -1e15;
int idx;
long long sqr(long long x){
    return x * x;
}
long long solve(int i){
    long long res = 1LL * i * i + (a - i);
    long long cnt1 = a - i + 2;
    long long cnt = b % cnt1;
    long long tmp = cnt * sqr((b / cnt1) + 1);
    tmp += (cnt1 - cnt) * sqr(b / cnt1);
    res -= tmp;
    return res;
}
void printt(int val , char s){
    while(val--){
        printf("%c" , s);
    }
}
void print(int i){
    vector < int > v;
    int cnt1 = a - i + 2;
    int cnt = b % cnt1;
    for(int i = 0 ; i < cnt ; ++i){
        v.emplace_back((b / cnt1) + 1);
    }
    for(int i = 0 ; i < b - cnt ; ++i){
        v.emplace_back(b / cnt1);
    }
    vector < int > v2;
    v2.emplace_back(i);
    for(int j = i + 1 ; j <= a ; ++j){
        v2.emplace_back(1);
    }
    int x = 0;
    int y = 0;
    for(int j = 1 ; j <= a - i + 1 + a - i + 2 ; ++j){
        if(j & 1){
            printt(v[x++] , 'x');
        }
        else{
            printt(v2[y++] , 'o');
        }
    }
}
int main(){
    cin >> a >> b;
    if(!a){
        cout << -sqr(b) << endl;
        for(int i = 0 ; i < b ; ++i){
            cout << "x";
        }
        return 0;
    }
    if(!b){
        cout << sqr(a) << endl;
        for(int i = 0 ; i < a ; ++i){
            cout << "o";
        }
        return 0;
    }
    for(int i = 1 ; i <= a ; ++i){
        long long tmp = solve(i);
        if(tmp > ans){
            ans = tmp;
            idx = i;
        }
    }
    cout << ans << "\n";
    print(idx);
}