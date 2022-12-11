#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second
#define t abs

int main(){

    int f,s;
    cin >> f >> s;
    int am = 0;
    while((f >= 2 && s >= 1) || (f >= 1 && s >= 2)){
        if(f > s){
            s--;
            f-=2;
            am++;
        }
        else{
            s-=2;
            f--;
            am++;
        }
    }
    cout << am;
    return 0;
}